#include "mgmt_mainwindow.h"
#include "ui_mgmtsystem.h"

#include <QRadioButton>

extern DB_Construction DB;
extern PublicSignal pub_sig;

Mgmt_MainWindow::Mgmt_MainWindow(QWidget *parent) :
    QMainWindow(parent)
    ,mgmt_form(new Ui::mgmtsystem)
{
    qout << "Begin Mgmt_MainWindow loading...";
    flwid->setWindowTitle("UserQube-管理系统界面");
    flwid->setWindowIcon(QIcon(":/icon/LOGO.png"));
    UiInit();
    ComOp::setFrameLess(flwid,this);
    ConnectInit();

    /* 这几行是测试代码
    QList<SQLdata> test;
    test.append({"mgmtsysalltabledb",Null_Type});
    test.append({"admin''s Test_mgmt",Char_Type});
    MgmtInfoInit(test);
    firstload = false;
    */
}

void Mgmt_MainWindow::ConnectInit()
{
    connect(&pub_sig,&PublicSignal::CallMgmtSystem,this,&Mgmt_MainWindow::MgmtInfoInit);
    UiConnectInit();
}

void Mgmt_MainWindow::UiConnectInit()
{
    connect(mgmt_form->chart_btn,btnclicked,this,&Mgmt_MainWindow::ChartSetting);
    connect(mgmt_form->addbtn,btnclicked,this,&Mgmt_MainWindow::AddData);
    connect(mgmt_form->editbtn,btnclicked,this,&Mgmt_MainWindow::EditData); //将新数据更新到数据库中
    connect(mgmt_form->searchbtn,btnclicked,this,&Mgmt_MainWindow::SearchData);
    connect(mgmt_form->delbtn,btnclicked,this,&Mgmt_MainWindow::DelData);
    connect(mgmt_form->norbtn,btnclicked,this,&Mgmt_MainWindow::SearchClose); //点击btn时关闭搜索模式
    //Tree点击时切换至对应表中
    connect(mgmt_form->tabselect_tree,&QTreeWidget::itemClicked,
            [=](QTreeWidgetItem * it,int){
        int index = mgmt_form->tabselect_tree->indexOfTopLevelItem(it);
        mgmt_form->stackedWidget->setCurrentIndex(index);
    });
    //StackedWidget的变化也会反过来改变其他变量的显示状态
    connect(mgmt_form->stackedWidget,&QStackedWidget::currentChanged,this,[&](int index){
        currentID = index;
        mgmt_form->tableselect_box->setCurrentIndex(index);
        QString name = mgmt_form->tableselect_box->currentText(); //获取表名称
        mgmt_form->tabname->setText(name); //设置表名称Label
        QTreeWidgetItem * it = mgmt_form->tabselect_tree->topLevelItem(index);
        mgmt_form->tabselect_tree->setCurrentItem(it);

        if(searchMode[currentID]){
            mgmt_form->searchlab->show();
            mgmt_form->norbtn->show();
        } else {
            mgmt_form->searchlab->hide();
            mgmt_form->norbtn->hide();
        }
    });
}

void Mgmt_MainWindow::MgmtInfoInit(QList<SQLdata> mgmtname)
{
    if(!firstload) ResetAll();
    firstload = false;
    QStringList field = {"mgmtsysalltabledb","uniquename"};
    //tabname获取了这个管理系统的所有的表的名称
    //jsonset获取了这个管理系统的所有表对应的json设置
    QStringList dbtab = DB.TableDataGet("DBtablename",mgmtname,field);
    QStringList tabname = DB.TableDataGet("表名称",mgmtname,field);
    QStringList jsonstr = DB.TableDataGet("表信息",mgmtname,field);
    QStringList mgmt = DB.TableDataGet("管理系统名称",mgmtname,field);
    QStringList acc = DB.TableDataGet("account",mgmtname,field);

    account = acc[0];
    mgmt_name = mgmt[0];
    mgmt_form->tabselect_tree->setHeaderLabel(mgmt_name);

    //JSON类型形成
    for(QString str : jsonstr){
        QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
        QJsonObject jsonObject = jsonDoc.object();
        jsonlist.append(jsonObject);
    }

    //Combox与Tree初始化
    for(QString tab : tabname){
        mgmt_form->tableselect_box->addItem(tab);
        QTreeWidgetItem * it = new QTreeWidgetItem(mgmt_form->tabselect_tree);
        it->setText(0,tab);
    }

    //上下表切换按钮，因为这些connect随着表的信息变化，所有没有放在ConnectInit函数中
    connect(mgmt_form->nextbtn,btnclicked,this,[=](){
       int index = mgmt_form->stackedWidget->currentIndex();
       mgmt_form->stackedWidget->setCurrentIndex((index + 1) % tabname.size());
    });
    connect(mgmt_form->lastbtn,btnclicked,this,[=](){
       int index = mgmt_form->stackedWidget->currentIndex();
       mgmt_form->stackedWidget->setCurrentIndex(index - 1 >= 0 ? index - 1 : tabname.size() - 1);
    });

    //数据内容初始化
    DataUpdate(dbtab);

    qout << tabname;
    qout << dbtab;

    ShowUp();
    qout << "MgmtMW ShowUp Complete!";
}

void Mgmt_MainWindow::ChartSetting()
{
    widgetlist.clear();
    QList<SQLdata> field = getField();
    QWidget * wid = new QWidget;
    framelessWidget * fld_chart = new framelessWidget;
    fld_chart->setWindowTitle("UserQube-图表设置");
    fld_chart->setWindowIcon(QIcon(":/icon/LOGO.png"));
    QFormLayout * lay = new QFormLayout(wid);
    myMaterialButton * yes = new myMaterialButton("确认",wid);
    myMaterialButton * no = new myMaterialButton("取消",wid);

    ComOp::setFrameLess(fld_chart,wid);
    ComOp::setNotMax(fld_chart);
    if(!fieldConstrcutToWidget(field,wid,lay,Btn_Chart)){
       qout << "Create Widget failed!";
       return ;
    }

    connect(no,btnclicked,fld_chart,&QWidget::close);
    connect(yes,btnclicked,fld_chart,[=](){
        QComboBox * Xcom = qobject_cast<QComboBox*>(widgetlist[0]);
        QComboBox * Ycom = qobject_cast<QComboBox*>(widgetlist[1]);

        QString Xname = Xcom->currentText(),Yname = Ycom->currentText();
        QStringList Xlist = getDataFromField(Xname),Ylist = getDataFromField(Yname);
        Type xtype = getTypeFromField(Xname),ytype = getTypeFromField(Yname);
        if(Xlist.size() && Ylist.size())
            showChart(Xlist,Ylist,xtype,ytype);
        else
            QMessageBox::critical(fld_chart,"警告","所需字段存在无数据情况！");
        qout << "Show Chart Complete!";
        fld_chart->close();
    });

    QSpacerItem * spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    lay->addItem(spacer);
    lay->addRow(confirmBtnLayout(yes,no));

    fld_chart->show();
}

void Mgmt_MainWindow::AddData()
{
    widgetlist.clear();
    QList<SQLdata> field = getField();
    QWidget * wid = new QWidget;
    framelessWidget * fld_add = new framelessWidget;
    fld_add->setWindowTitle("UserQube-新增数据");
    fld_add->setWindowIcon(QIcon(":/icon/LOGO.png"));
    QFormLayout * lay = new QFormLayout(wid);
    myMaterialButton * yes = new myMaterialButton("确认",wid);
    myMaterialButton * no = new myMaterialButton("取消",wid);

    ComOp::setFrameLess(fld_add,wid);
    ComOp::setNotMax(fld_add);
    if(!fieldConstrcutToWidget(field,wid,lay,Btn_Add)){
       qout << "Create Widget failed!";
       return ;
    }

    connect(no,btnclicked,fld_add,&QWidget::close);
    connect(yes,btnclicked,wid,[=](){
        QStringList fieldcon = getFieldNameInSQLDataType(field);
        QList<SQLdata> input = getFieldinput(field);

        if(input.isEmpty()){
            QMessageBox::critical(wid,"警告","存在未输入或不合法的信息！");
            return ;
        }
        //使用DB.TableInsertOneData时，除了有内容，还需要有表名称作为标识码
        fieldcon.push_front(getDBtablename());
        input.push_front({getDBtablename(),Null_Type});
        if(!DB.TableInsertOneData(input,fieldcon))
            QMessageBox::critical(wid,"警告","出现错误，创建失败！");
        else
            QMessageBox::information(wid,"提示","创建成功！");

        modellist[currentID]->submitAll();
        widgetlist.clear();
        fld_add->close();
    });

    QSpacerItem * spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    lay->addItem(spacer);
    lay->addRow(confirmBtnLayout(yes,no));

    fld_add->show();
}

void Mgmt_MainWindow::ViewUpdateCheck(const QModelIndex &index)
{
    QList<SQLdata> field = getField();
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(sender());
    if (model) {
        Type type = field[index.column() - 1].second; //columu从1开始，需要减1
        qout << "Old Value:" << oldValue << " Type Num:" << type;;
        QVariant newValue = model->data(index, Qt::DisplayRole);
        qout << "New Value:" << newValue << " Type Num:" << type;

        if(oldValue != newValue)
        {
            model->setData(index,QBrush(Qt::green),Qt::BackgroundRole);
        }

        /* model有自动输入判断，所以这个函数其实没有太大的必要呢...
        if(newValue.isNull()){ //非空判断
            QMessageBox::critical(this,"警告","不能修改为空数据！");
            model->data(topLeft, Qt::DisplayRole).setValue(oldValue);
            return ;
        }

        if(type == Int_Type || type == Double_Type)
            if(!ComOp::isNumeric(newValue.toString())){
                QMessageBox::critical(this,"警告","错误的输入数据！");
                model->data(topLeft, Qt::DisplayRole).setValue(oldValue);
            }
         */
    }
}

void Mgmt_MainWindow::EditData()
{
    modellist[currentID]->submitAll();
    QMessageBox::information(this,"提示","更新成功！");
}

void Mgmt_MainWindow::SearchData()
{
    widgetlist.clear();
    dis_widgetset.clear();

    QList<SQLdata> field = getField();
    framelessWidget * fld_search = new framelessWidget;
    fld_search->setWindowTitle("UserQube-查询数据");
    fld_search->setWindowIcon(QIcon(":/icon/LOGO.png"));
    QWidget * wid = new QWidget;
    QFormLayout * lay = new QFormLayout(wid);
    myMaterialButton * yes = new myMaterialButton("确认",wid);
    myMaterialButton * no = new myMaterialButton("取消",wid);

    ComOp::setFrameLess(fld_search,wid);
    ComOp::setNotMax(fld_search);

    if(!fieldConstrcutToWidget(field,wid,lay,Btn_Search)){
       qout << "Create Widget failed!";
       return ;
    }

    QSpacerItem * spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    lay->addItem(spacer);
    lay->addRow(confirmBtnLayout(yes,no));
    connect(no,btnclicked,fld_search,&QWidget::close);
    connect(yes,btnclicked,wid,[=](){
        QStringList fieldcon = getFieldNameInSQLDataType(field);
        QStringList eql;
        QList<SQLdata> input = getFieldinput(field);

        //eql暂时全为=
        for(int i = 0;i < input.size();i++) eql.append("=");
        //fieldcon去除禁用的字段
        QStringList tmp = fieldcon;
        foreach (const int &i, dis_widgetset)
            tmp.removeOne(fieldcon[i]);
        fieldcon = tmp;

        if(input.isEmpty()){
            QMessageBox::critical(wid,"警告","存在未输入或不合法的信息！");
            return ;
        }
        //使用DB.TableInsertOneData时，除了有内容，还需要有表名称作为标识码
        fieldcon.push_front(getDBtablename());
        eql.push_front(getDBtablename()); //为了一致性，eql也增加一个标识码
        input.push_front({getDBtablename(),Null_Type});

        QString Filter = DB.TableDataSearch(input,fieldcon,eql);
        if(Filter.isEmpty())
            QMessageBox::critical(wid,"警告","出现错误，创建失败！");
        else
        {
            modellist[currentID]->setFilter(Filter);
            if(!modellist[currentID]->rowCount()){
                modellist[currentID]->setFilter("");
                QMessageBox::critical(wid,"警告","未找到任何数据！");
                return ;
            }
            modellist[currentID]->select();
            //搜索模式提示开启
            searchMode[currentID] = true;
            mgmt_form->searchlab->show();
            mgmt_form->norbtn->show();

            QMessageBox::information(wid,"提示","创建成功！");
        }
        widgetlist.clear();
        dis_widgetset.clear();
        fld_search->close();
    });

    fld_search->show();
}

void Mgmt_MainWindow::DelData()
{
    QTableView * view = viewlist[currentID];
    QModelIndexList rows = view->selectionModel()->selectedIndexes();

    //无数据选择判断
    if(rows.isEmpty()){
        QMessageBox::critical(this,"警告","无选中数据，删除无效！");
        return ;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this,
                            "信息", "确认删除吗?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) return ;

    //遍历所有被选中的行
    for (const QModelIndex &index : rows)
        modellist[currentID]->removeRow(index.row());

    if(!modellist[currentID]->submitAll())
        qout << "删除失败！";
}

bool Mgmt_MainWindow::fieldConstrcutToWidget(QList<SQLdata> field,QWidget * wid,QFormLayout * lay,
                                             BtnCommandType btntype)
{
    int cnt = 0;
    QComboBox *linetype,*Xcombo,*Ycombo;
    if(btntype == Btn_Chart){
        linetype = new QComboBox;
        linetype->addItem("柱状图");
        linetype->addItem("折线图");
        linetype->addItem("饼状图");
        Xcombo = new QComboBox;
        Ycombo = new QComboBox;

        widgetlist.append(Xcombo);
        widgetlist.append(Ycombo);
        lay->addRow("选择类型:",linetype);
        lay->addRow("选择X轴:",Xcombo);
        lay->addRow("选择Y轴:",Ycombo);
    }

    for(SQLdata info : field)
    {
        QString name = info.first;
        Type type = info.second;
        if(name.isEmpty() || type == Null_Type) return false;
        if(btntype == Btn_Chart) {
            Xcombo->addItem(name);
            Ycombo->addItem(name);
            continue;
        }
        if(type == Int_Type || type == Char_Type || type == Double_Type)
        {
            QLineEdit * line = new QLineEdit(wid);
            widgetlist.append(line);
            if(btntype == Btn_Add)
                lay->addRow(name + ":",line);
            else if(btntype == Btn_Search)
                lay->addRow(name + ":",disBtnSetting(QList<QWidget*>() << line,cnt));
        }
        else if(type == Bool_Type)
        {
            QButtonGroup * box = new QButtonGroup;
            QRadioButton * tru = new QRadioButton("是",wid);
            QRadioButton * fal = new QRadioButton("否",wid);
            QHBoxLayout * btnlay = new QHBoxLayout;
            widgetlist.append(tru); tru->setChecked(true); //默认为true
            btnlay->addWidget(tru); box->addButton(tru);
            btnlay->addWidget(fal); box->addButton(fal);
            if(btntype == Btn_Add)
                lay->addRow(name + ":",btnlay);
            else if(btntype == Btn_Search)
                lay->addRow(name + ":",disBtnSetting(QList<QWidget*>()<< tru << fal,cnt));
        }
        else if(type == Date_Type)
        {
            //以现在的时间为初始时间
            QDateTimeEdit * timeset = new QDateTimeEdit(QDateTime::currentDateTime());
            QString timedisplay = ComOp::TimeEditSetting(jsonlist[currentID],name,timeset);
            qout << jsonlist[currentID] << " TimeDisplay:"
                 << timedisplay << " Time:" << timeset->dateTime().toString();
            //toString()是为了防止调试输出乱码
            timeset->setDisplayFormat(timedisplay);
            widgetlist.append(timeset);
            if(btntype == Btn_Add)
                lay->addRow(name + ":",timeset);
            else if(btntype == Btn_Search)
                lay->addRow(name + ":",disBtnSetting(QList<QWidget*>()<< timeset,cnt));
        }
        cnt ++;
    }
    return true;
}

void Mgmt_MainWindow::showChart(const QStringList &xData, const QStringList &yData,
                                const Type xtype,const Type ytype)
{
    int a = 0,b = 0;
    if(xtype) a ++;
    if(ytype) b ++;
    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();
    // 创建一个柱状集合对象，并将数据添加到集合中
    QBarSet *barSet = new QBarSet("图线");
    double maxY = 0,minY = 0;
    for (int i = 0; i < xData.size(); ++i) {
        *barSet << yData[i].toDouble();
        maxY = std::max(maxY,yData[i].toDouble());
        if(yData[i].toDouble() < 0)
            minY = std::min(minY,yData[i].toDouble());
    }
    series->append(barSet);
    chart->addSeries(series);
    // 设置x轴和y轴，不得不说默认的设置真的不怎么样
    chart->createDefaultAxes();
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->axes(Qt::Vertical).first()->setRange(minY,maxY * 1.05);
    QBarCategoryAxis * axisX = qobject_cast<QBarCategoryAxis*>
            (chart->axes(Qt::Horizontal).first());
    axisX->setCategories(xData);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    //柱状图动画设置:当鼠标悬挂在柱状图上面时，会显示具体数值
    connect(series,&QBarSeries::hovered,series,
            [=](bool status,int barIndex,QBarSet *barset)
    {
        static qreal barWidth;
        static qreal barHeight;
        if(status) {
            barHeight = yData[barIndex].toDouble();
            barWidth = series->barWidth();
            barset->replace(barIndex + barWidth * 0.05,barHeight + barHeight * 0.05);
            QString Reg = QString("<font famliy=微软雅黑><font color=black>数值: %1</font></font>")
                          .arg(barHeight);
            barset->setLabel(Reg);
        } else {
            barset->replace(barIndex,barHeight);
            barset->setLabel("图线");
        }
    });

    // 创建一个图表视图对象
    QChartView *chartView = new QChartView(chart);
    // 显示图表
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->show();
    framelessWidget * fld_chart = new framelessWidget;
    fld_chart->setWindowTitle("UserQube-图表设置");
    fld_chart->setWindowIcon(QIcon(":/icon/LOGO.png"));
    ComOp::setFrameLess(fld_chart,chartView);
    fld_chart->resize(1000,600);
    // 显示图表
    chartView->setRenderHint(QPainter::Antialiasing);
    fld_chart->show();
}

QList<SQLdata> Mgmt_MainWindow::getFieldinput(QList<SQLdata> field)
{
    qout << widgetlist;
    QList<SQLdata> input;
    for (int i = 0;i < widgetlist.size();i++)
    {
        Type type = field[i].second;
        QWidget * littlewid = widgetlist[i];
        if(!littlewid->isEnabled()) continue; //如果禁用则不管
        if (auto lineEdit = qobject_cast<QLineEdit*>(littlewid)){
            if(lineEdit->text().isEmpty()){
                input.clear();
                return input;
            }
            if(type == Int_Type || type == Double_Type)
                if(!ComOp::isNumeric(lineEdit->text())){
                    input.clear();
                    return input;
                }
            input.append({lineEdit->text(),type});
        }
        else if (auto radioBtn = qobject_cast<QRadioButton*>(littlewid)){
            input.append({radioBtn->isChecked() ? "1" : "0",type});
        }
        else if (auto dateTimeEdit = qobject_cast<QDateTimeEdit*>(littlewid)){
            input.append({dateTimeEdit->dateTime().toString("yyyy/MM/dd hh:mm"),type});
        }
    }
    qout << input;
    return input;

}

QHBoxLayout* Mgmt_MainWindow::confirmBtnLayout(QPushButton * yes,QPushButton * no)
{
    QHBoxLayout * lay = new QHBoxLayout;
    lay->addWidget(yes);
    lay->addWidget(no);
    return lay;
}

void Mgmt_MainWindow::DataUpdate(QStringList dbtab)
{
    int cnt = 0;
    for(QString tab : dbtab){
        //Widget初始化
        QWidget * wid = new QWidget;
        QTableView * view = new QTableView(wid);

        QHBoxLayout * lay = new QHBoxLayout(wid);  //水平布局
        modellist.append(DB.DBToTableView(wid,tab));
        viewlist.append(view);
        searchMode.append(false);

        //特殊数据设置，需要进行遍历
        QList<SQLdata> field = DB.TableFieldGet(tab);
        for(int i = 0;i < field.size();i++){
            QString name = field[i].first;
            Type type = field[i].second;
            if(type == Date_Type)
            {
                QString timedisplay = ComOp::TimeEditSetting(jsonlist[cnt],name);
                qout << jsonlist[cnt] << " TimeDisplay:" << timedisplay;
                view->setItemDelegateForColumn(i,new DateTimeDelegate(timedisplay));
            } else if(type == Bool_Type) {
                view->setItemDelegateForColumn(i,new BoolDelegate());
            }
        }

        view->setSortingEnabled(true); //开启排序
        view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //保持水平伸展状态
        view->horizontalHeader()->setSortIndicatorShown(false); //为了保持一致性就不要Indicator了
        //双击返回正常序列
        connect(view->horizontalHeader(),&QHeaderView::sectionDoubleClicked, this,[=](){
            //这里不能直接用view
            modellist[currentID]->setSort(-1, Qt::AscendingOrder);
            modellist[currentID]->select();
        });
        //View数据更改时，进行合法性检测,不过现在似乎用处不大
        connect(view,&QTableView::doubleClicked,this,[&](const QModelIndex &index){
            oldValue = index.data();
        }); //获取修改前的值
        connect(modellist.back(),&QSqlTableModel::dataChanged,this,&Mgmt_MainWindow::ViewUpdateCheck);

        //实现列表表头修改列宽度功能
        /* 然而这个功能并不能实现，因为设置为Stretch后就无法进行Interact了
        QHeaderView *header = view->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Interactive);
        header->setSectionResizeMode(QHeaderView::Stretch);
        connect(header, &QHeaderView::sectionResized, this, [=](int logicalIndex,int,int newSize){
            view->setColumnWidth(logicalIndex, newSize);
        });
        */

        view->setModel(modellist.back());
        view->hideColumn(0);
        lay->addWidget(view);
        mgmt_form->stackedWidget->addWidget(wid);
        qout << view;
        cnt ++;
    }
}

QHBoxLayout* Mgmt_MainWindow::disBtnSetting(QList<QWidget*> wid,int cnt)
{
    myMaterialButton * btn = new myMaterialButton("◈");
    QHBoxLayout * lay = new QHBoxLayout;

    btn->setMaximumSize(30,28);
    btn->setMinimumSize(30,28);
    connect(btn,btnclicked,this,[=](){
        QString st = btn->text();
        if(st == "◈") {
            for(QWidget* it : wid)
                it->setDisabled(true);
            btn->setText("◇");
            dis_widgetset.insert(cnt);
        } else {
            for(QWidget* it : wid)
                it->setDisabled(false);
            btn->setText("◈");
            dis_widgetset.remove(cnt);
        }
        qout << dis_widgetset;
    });

    for(QWidget* it : wid)
        lay->addWidget(it);
    lay->addWidget(btn);
    return lay;
}

inline void Mgmt_MainWindow::SearchClose()
{
    searchMode[currentID] = false;
    modellist[currentID]->setFilter("");
    mgmt_form->norbtn->hide();
    mgmt_form->searchlab->hide();
}

QStringList Mgmt_MainWindow::getDataFromField(QString fieldname)
{
    QList<SQLdata> input = {{getDBtablename(),Null_Type}};
    QStringList fieldcon = {getDBtablename()};
    QStringList output = DB.TableDataGet(fieldname,input,fieldcon);
    return output;
}

Type Mgmt_MainWindow::getTypeFromField(QString fieldname)
{
    QString cond = getDBtablename();
    QList<SQLdata> field = DB.TableFieldGet(cond);
    for(SQLdata it : field)
        if(it.first == fieldname)
            return it.second;
    return Null_Type;
}

inline QList<SQLdata> Mgmt_MainWindow::getField()
{
    QString cond = getDBtablename();
    QList<SQLdata> field = DB.TableFieldGet(cond);
    field.pop_front(); //第一个默认id作为隐式数据内容，不需要进行增删改查等操作，因此需要pop掉
    return field;
}

inline QString Mgmt_MainWindow::getDBtablename()
{
    return "USER_" + account + "_" + mgmt_name + "_" + mgmt_form->tabname->text();
}

inline QStringList Mgmt_MainWindow::getFieldNameInSQLDataType(QList<SQLdata> field)
{
    QStringList res;
    for(SQLdata name : field)
        res.append(name.first);
    return res;
}

inline void Mgmt_MainWindow::ResetAll()
{
    jsonlist.clear();
    modellist.clear();
    viewlist.clear();
    searchMode.clear();
    widgetlist.clear();
    dis_widgetset.clear();
    currentID = 0;
    if(mgmt_form != nullptr)
    {
        delete mgmt_form;
        mgmt_form = new Ui::mgmtsystem;
        UiInit();
        UiConnectInit();
        qout << "MgmtMW Reset Complete!";
    }
}

void Mgmt_MainWindow::UiInit()
{
    mgmt_form->setupUi(this);
    //需要将ui中的原来的widget进行删除
    QWidget* widget_1 = mgmt_form->stackedWidget->widget(0);
    QWidget* widget_2 = mgmt_form->stackedWidget->widget(1);
    mgmt_form->stackedWidget->removeWidget(widget_1);
    mgmt_form->stackedWidget->removeWidget(widget_2);
    //先隐藏搜索提示
    mgmt_form->searchlab->hide();
    mgmt_form->norbtn->hide();
    mgmt_form->tabselect_tree->header()->setHidden(false);
}

void Mgmt_MainWindow::ShowUp()
{
    flwid->resize(1200,900);
    flwid->show();
}

Mgmt_MainWindow::~Mgmt_MainWindow()
{
    qout << "Mgmt_MainWindow closed";
}
