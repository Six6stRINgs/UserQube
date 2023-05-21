#include "create_mainwindow.h"
#include "ui_create_mainwindow.h"

extern DB_Construction DB;
extern PublicSignal pub_sig;

Create_MainWindow::Create_MainWindow(QWidget *parent) :
    QMainWindow(parent)
    ,create_form(new Ui::Create_MainWindow)
{
    qout << "Begin Create_MainWindow loading...";
    flwid->setWindowTitle("UserQube-新建界面");
    flwid->setWindowIcon(QIcon(":/icon/LOGO.png"));
    ComOp::setFrameLess(flwid,this);
    create_form->setupUi(this);
    //为了同一进行操作，这里需要先将stackedwidget中的第一页删除
    //QList下标从0开始，而表从1开始，注意这里需要进行对应
    create_form->stackedWidget->removeWidget(create_form->stackedWidget->widget(1));

    TreeInit();
    Table_creat();
    ConnectInit();
}

void Create_MainWindow::TreeInit()
{
    top->setText(0,"管理系统设置");
    create_form->treeWidget->addTopLevelItem(top);
    create_form->treeWidget->expandAll(); //设置为自动展开
    //点击item将跳转到对应的wigdet
    connect(create_form->treeWidget,&QTreeWidget::itemClicked,
            [=](QTreeWidgetItem * it,int){
        if(it->parent() == top)
        {
            int index = top->indexOfChild(it) + 1; //注意需要加1
            create_form->stackedWidget->setCurrentIndex(index);
        } else if(it == top)
            create_form->stackedWidget->setCurrentIndex(0);
    });
}

void Create_MainWindow::ConnectInit()
{
    connect(&pub_sig,&PublicSignal::CallCreate,this,&Create_MainWindow::ShowUp);
    connect(create_form->addtable,btnclicked,this,&Create_MainWindow::Table_creat);
    connect(create_form->deltable,btnclicked,this,&Create_MainWindow::Table_del);
    connect(create_form->createbtn,btnclicked,this,&Create_MainWindow::InfoRead);
}

void Create_MainWindow::Table_creat()
{
    table_cnt++;
    Table_Widget * tablewig = new Table_Widget(this);
    Field_Widget * fieldwig = tablewig->findChild<Field_Widget *>("field_widget");

    //增加treewidget子控件
    QTreeWidgetItem * it = new QTreeWidgetItem(top);
    it->setText(0,QString("表设置%1").arg(table_cnt));

    //增加/删除 字段设置
    QPushButton * addfield = tablewig->findChild<QPushButton *>("addfield");
    QPushButton * delfield = tablewig->findChild<QPushButton *>("delfield");
    connect(addfield,btnclicked,this,&Create_MainWindow::NewField_create);
    connect(delfield,btnclicked,this,&Create_MainWindow::DelField_Last);

    //加入到全局容器中进行保存（存入指针）
    QList<Field_Widget *> field_list;
    field_list.append(fieldwig);
    table_list.append({field_list,tablewig});

    //增加wigdet到界面中
    create_form->stackedWidget->addWidget(tablewig);
}

void Create_MainWindow::Table_del()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                            "警告", "删除的表可能存在填入信息，确认删除?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if(table_cnt == 1)
            QMessageBox::critical(this,"警告","至少有一个表！");
        else
        {
            //确认后再执行代码，需要先进行内存释放
            delete table_list.back().table;
            table_list.pop_back();
            top->removeChild(top->takeChild(--table_cnt));
        }
    }
}

void Create_MainWindow::NewField_create()
{
    //定位当前的字段Layout
    int index = create_form->stackedWidget->currentIndex();
    QWidget * table = create_form->stackedWidget->widget(index);
    QVBoxLayout * scroll = table->findChild<QVBoxLayout *>("fieldlayout");
    //增加新的字段框
    Field_Widget * fieldwig = new Field_Widget(table);
    //表的下标从1开始，而QList从0开始，所以需要减1进行下标对应
    table_list[index - 1].field.append(fieldwig);
    scroll->addWidget(fieldwig);
}

void Create_MainWindow::DelField_Last()
{
    //定位当前index
    int index = create_form->stackedWidget->currentIndex();
    QWidget * table = create_form->stackedWidget->widget(index);
    //寻找Layout
    QVBoxLayout * scroll = table->findChild<QVBoxLayout *>("fieldlayout");
    //减1与上面同理
    Field_Widget * field = table_list[index - 1].field.back();
    QLineEdit * input = field->findChild<QLineEdit *>("name_input");

    if(!input->text().isEmpty()){
        QMessageBox::critical(this,"警告","存在输入信息，无法删除！");
    } else {
        if(table_list[index - 1].field.size() == 1)
            QMessageBox::critical(this,"警告","至少有一个字段！");
        else {
            scroll->removeWidget(field);
            table_list[index - 1].field.pop_back();
            delete field;
        }
    }
}

void Create_MainWindow::InfoRead()
{
    if(!ALLNotNullCheck()) {
        QMessageBox::critical(this,"错误","存在空信息或空格，请再次确认。");
        return ;
    }
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                            "信息", "确认创建吗?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) return ;

    //从这里才开始进行数据操作
    QList<SQLdata> input = get_mgmtsysBaseInfo();
    mgmtname.append({"mgmtsysalltabledb",Null_Type});
    mgmtname.append({input[3].first,Char_Type});//input[3]对应为uniquename字段
    if(DB.TableInsertOneData(input,DB.mgmtsysField))
    {
        QString user = "USER_" + account + '_' + create_form->mgmtsys_input->text() + '_';
        qout << "Add data into MySQL table \"mgmtsysdb\" successfully";
        for(auto table_it : table_list)
            if(!infoCollect(user,table_it)){
                QMessageBox::critical(this,"警告","出现错误，创建失败");
                return ;
            }
        QMessageBox::information(this,"完成","创建成功");
        //成功创建后将自动进入管理系统界面
        emit pub_sig.CallMgmtSystem(mgmtname);
        mgmtname.clear();
        flwid->hide();
    } else {
        QMessageBox::critical(this,"错误","添加失败");
        return ;
    }
}

bool Create_MainWindow::infoCollect(QString user,cre_table tab)
{
    QWidget * tabwig = tab.table;
    QLineEdit * tabname = tabwig->findChild<QLineEdit *>("tablename_input");
    QTextEdit * desc = tabwig->findChild<QTextEdit *>("describe_input");
    //第一个信息为表名
    QStringList name = {user + tabname->text()},typeset = {user + tabname->text()};
    //每一个表都有一个默认的字段"ID_DEFAULT"作为主键
    name.append("ID_DEFAULT");
    typeset.append("int auto_increment primary key unique");
    QString jsoninfo = "{"; //用与sql表中的json类型，每个表有一个json对象类型数据
    int fielcnt = 0,jsoncnt = 0;

    for(auto field_it : tab.field){
        QLineEdit * field = field_it->findChild<QLineEdit *>("name_input");
        QString fieldname = field->text();//字段开头不能为数字
        if(fieldname[0] >= '0' && fieldname[0] <= '9'){
            QMessageBox::information(this,"警告","字段不能以数字开头");
            return false;
        }
        QComboBox * type = field_it->findChild<QComboBox *>("type_combo");
        name.append(fieldname);

        if(type->currentIndex() == 0){ //整数型
            //决定类型
            QRadioButton * typebtn = field_it->findChild<QRadioButton *>("int_btn");
            if(typebtn->isChecked()) typeset.append("int");
            else typeset.append("bigint");
            //决定无符号
            QCheckBox * uns = field_it->findChild<QCheckBox *>("int_uns");
            if(uns->isChecked()) typeset.back() += " unsigned ";
            //决定唯一
            QCheckBox * unq = field_it->findChild<QCheckBox *>("int_unq");
            if(unq->isChecked()) typeset.back() += " unique ";
        } else if(type->currentIndex() == 1) {//浮点型
            typeset.append("double");
            //决定无符号
            QCheckBox * uns = field_it->findChild<QCheckBox *>("double_uns");
            if(uns->isChecked()) typeset.back() += " unsigned ";
            //决定唯一
            QCheckBox * unq = field_it->findChild<QCheckBox *>("double_unq");
            if(unq->isChecked()) typeset.back() += " unique ";
        } else if(type->currentIndex() == 2) {//字符串型
            QLineEdit * len = field_it->findChild<QLineEdit *>("char_len_input");
            QRadioButton * typebtn = field_it->findChild<QRadioButton *>("char_box");
            if(typebtn->isChecked()) typeset.append("char");
            else typeset.append("varchar");
            typeset.back() += QString("(%1)").arg(len->text());
            //决定唯一
            QCheckBox * unq = field_it->findChild<QCheckBox *>("char_unq");
            if(unq->isChecked()) typeset.back() += " unique ";
        } else if(type->currentIndex() == 3){//布尔型，用1位int表示
            typeset.append("tinyint(1)");
        } else {//时间型
            //顺序为:年，月，日，时
            if(jsoncnt) jsoninfo += ",";
            QList<QCheckBox *> timeset = field_it->findChildren<QCheckBox *>
                    (QRegularExpression("^time_.*"));
            jsoninfo += "\"" + fieldname + "\":[";
            for(int i = 0;i < timeset.size();i++)
            {
                if(i) jsoninfo += ",";
                jsoninfo += timeset[i]->checkState() ? "1" : "0";
            }
            jsoninfo += "]";
            jsoncnt ++;
            typeset.append("datetime");
        }
        fielcnt ++;
    }
    jsoninfo += "}";
    //这个tabledata用于mgmtsysalltabledb表中，表示一个表的总体信息
    QList<SQLdata> tabledata = {{"mgmtsysalltabledb",Null_Type}};
    //tablename作为唯一标识
    tabledata.append({name[0],Char_Type});
    tabledata.append({mgmtname[1].first,Char_Type});
    tabledata.append({account,Char_Type});
    tabledata.append({create_form->mgmtsys_input->text(),Char_Type});
    tabledata.append({tabname->text(),Char_Type});
    tabledata.append({desc->toPlainText(),Char_Type});
    tabledata.append({QString::number(fielcnt),Int_Type});
    tabledata.append({jsoninfo,Json_Type});
    if(DB.TableInsertOneData(tabledata,DB.mgmtsysalltableField)){
        qout << "Add data into MySQL table \"mgmtsysalltabledb\" successfully";
    } else {
        qout << "ERROR:data \"" << name.front() <<"\"insert failed";
        return false;
    }
    //创建对应表具体的字段设置
    name.append(desc->toPlainText());
    typeset.append(desc->toPlainText());
    if(DB.TableCreate(name,typeset)){
        qout << "Create MySQL table \"" << name.front() <<  "\" successfully";
        return true;
    } else {
        qout << "ERROR:table \"" << name.front() <<"\"create failed";
        return false;
    }
}

QList<SQLdata> Create_MainWindow::get_mgmtsysBaseInfo()
{
    QList<SQLdata> data = {{"mgmtsysdb",Null_Type}};
    data.append({account,Char_Type});
    data.append({create_form->mgmtsys_input->text(),Char_Type});
    //对应uniquename字段，是唯一标识，防止重复的名称
    data.append({account + "''s " + create_form->mgmtsys_input->text(),Char_Type});
    data.append({create_form->mgmtdes_input->toPlainText(),Char_Type});
    data.append({QString::number(table_cnt),Int_Type});
    return data;
}

bool Create_MainWindow::ALLNotNullCheck()
{
    //管理系统输入非空判断，其中管理系统名称不能有空格
    if(create_form->mgmtsys_input->text().isEmpty() ||
       create_form->mgmtsys_input->text().contains(' ') ||
       create_form->mgmtdes_input->toPlainText().isEmpty()){
        qout << "ERROR:mgmt Empty";
        return false;
    }

    for(auto table_it : table_list)
    {
        QWidget * wid = table_it.table;
        QLineEdit * tabname = wid->findChild<QLineEdit *>("tablename_input");
        QTextEdit * desc = wid->findChild<QTextEdit *>("describe_input");
        //表非空判断，其中表名不能为空
        if(tabname->text().isEmpty() || tabname->text().contains(' ') ||
           desc->toPlainText().isEmpty()){
            qout << "ERROR:table Empty";
            return false;
        }
        //字段非空判断
        for(auto field_it : table_it.field){
            if(!fieldwig_NotNullCheck(field_it)){
                qout << "ERROR:field Empty";
                return false;
            }
        }
    }
    return true;
}

bool Create_MainWindow::fieldwig_NotNullCheck(Field_Widget *wid)
{
    //字段非空判断，同时也不能带有空格
    QLineEdit * name = wid->findChild<QLineEdit *>("name_input");
    if(name->text().isEmpty() || name->text().contains(' ')) return false;

    //定位当前选择的类型
    QComboBox * typeset = wid->findChild<QComboBox *>("type_combo");
    int index = typeset->currentIndex();
    //index为2时，为char型，需要输入长度，所以需要非空判定
    if(index == 2) {
        QLineEdit * len = wid->findChild<QLineEdit *>("char_len_input");
        if(len->text().isEmpty() || !ComOp::isNumeric(len->text())) return false;
    } else if(index == 4) {
        //index为4时，为时间型，年月日时至少需要选择一个
        bool allnull = false;
        QList<QCheckBox *> timeset = wid->findChildren<QCheckBox *>(QRegularExpression("^time_.*"));
        for(auto it : timeset) allnull |= it->checkState();
        if(!allnull) return false;
    }
    return true;
}

void Create_MainWindow::ShowUp(QString cre_account)
{
    account = cre_account;
    flwid->resize(1200,900);
    flwid->show();
    qout << "CreateMW ShowUp Complete!";
}

Create_MainWindow::~Create_MainWindow()
{
    qout << "Create_MainWindow closed";
}
