#include "personal_mainwindow.h"
#include "ui_Personal_MainWindow.h"

#include <QStandardItemModel>

extern DB_Construction DB;
extern PublicSignal pub_sig;

Personal_MainWindow::Personal_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , personal_form(new Ui::Personal_MainWindow)
{
    qout << "Begin Personal_MainWindow loading...";
    flwid->setWindowTitle("UserQube-个人界面");
    flwid->setWindowIcon(QIcon(":/icon/LOGO.png"));
    ComOp::setFrameLess(flwid,this);
    UiInit();

    ConnectInit();
    /* 测试代码
    LoginConnect("admin");
    firstLoad = false;
    */
}

void Personal_MainWindow::UiInit()
{
    personal_form->setupUi(this);
    //第一页不需要(只需要第0页)
    QWidget * w1 = personal_form->stackedWidget->widget(1);
    personal_form->stackedWidget->removeWidget(w1);
    QTreeWidgetItem * initpage = new QTreeWidgetItem(personal_form->treeWidget);
    initpage->setText(0,"初始页");
    personal_form->selectbtn->setDisabled(true);
}

void Personal_MainWindow::ConnectInit()
{
    connect(&pub_sig,&PublicSignal::login_successfully,this,&Personal_MainWindow::LoginConnect);
    UiConnectInit();
}

void Personal_MainWindow::UiConnectInit()
{
    connect(personal_form->create_btn,btnclicked,this,&Personal_MainWindow::CallCreateWindow);
    //StacjedWidget的变化也会反过来改变其他变量的显示状态
    connect(personal_form->stackedWidget,&QStackedWidget::currentChanged,this,[&](int index){
        currentID = index;
        //第0页为初始页，不能进行管理系统选择
        if(currentID) personal_form->selectbtn->setDisabled(false);
        else personal_form->selectbtn->setDisabled(true);
    });
    //Tree点击时切换至对应表中
    connect(personal_form->treeWidget,&QTreeWidget::itemClicked,
            [=](QTreeWidgetItem * it,int){
        int index = personal_form->treeWidget->indexOfTopLevelItem(it);
        personal_form->stackedWidget->setCurrentIndex(index);
    });
    //双击tree控件时，进入对应的管理系统
    connect(personal_form->treeWidget,&QTreeWidget::doubleClicked,this,[=](const QModelIndex &model){
        int index = model.row();
        if(!index){ //第0页为初始页，不能进入管理系统
            return ;
        }
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                                "信息", "确认选择此管理系统吗?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No) return ;

        emit pub_sig.CallMgmtSystem(mgmtlist[index]);
        flwid->hide();
    });

    connect(personal_form->selectbtn,btnclicked,this,[=](){
       emit pub_sig.CallMgmtSystem(mgmtlist[currentID]);
    });
}

void Personal_MainWindow::CallCreateWindow()
{
    flwid->hide();
    emit pub_sig.CallCreate(account);
}

void Personal_MainWindow::LoginConnect(QString name)
{   
    if(!firstLoad) ResetAll();
    account = name;
    personal_form->account_lab->setText(account);
    QStringList field = {"mgmtsysdb","account"};
    QList<SQLdata> input = {{"mgmtsysdb",Null_Type},{account,Char_Type}};
    QStringList mgmt = DB.TableDataGet("sysname",input,field);
    QStringList mgmtdes = DB.TableDataGet("describle",input,field);
    //由于初始页的存在，为了下标对齐，所以mgmtlist也有第0页，但并不存储什么值
    mgmtlist.append(QList<SQLdata>{{0,Null_Type}});

    //增加管理系统至tree表
    for(int i = 0;i < mgmt.size();i++)
    {
        QString name = mgmt[i],des = mgmtdes[i];
        QList<SQLdata> mgmtinfo = {{{"mgmtsysalltabledb",Null_Type}}};
        mgmtinfo.append({account + "''s " + name,Char_Type});
        mgmtlist.append(mgmtinfo);
        QTreeWidgetItem * it = new QTreeWidgetItem(personal_form->treeWidget);
        it->setText(0,name);

        UiTreeTableInit(name,des,mgmtinfo);
    }

    ShowUp();
    qout << "PersonalMW ShowUp Complete!";
}

void Personal_MainWindow::UiTreeTableInit(QString mgmtname,QString mgmtdes,QList<SQLdata> mgmtinfo)
{
    MgmtInfo_Widget * mgwid = new MgmtInfo_Widget;
    mgwid->ui->mgmt_lab->setText(mgmtname);
    mgwid->ui->mgmtdes_lab->setText(mgmtdes);

    QStringList field = {"mgmtsysalltabledb","uniquename"},
                tabname = DB.TableDataGet("表名称",mgmtinfo,field),
                tabdes = DB.TableDataGet("表描述",mgmtinfo,field),
                fieldcnt = DB.TableDataGet("表字段数",mgmtinfo,field),
                dbtabe = DB.TableDataGet("DBtablename",mgmtinfo,field);


    QStandardItemModel * model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList() << "表名称" << "描述" << "字段名称" << "数据数/类型");

    //增加表
    for(int i = 0;i < tabname.size();i++){
        int tabcnt = DB.TableDataCntGet(dbtabe[i]);

        QList<QStandardItem *> row;
        row << new QStandardItem(tabname[i])
            << new QStandardItem(tabdes[i])
            << new QStandardItem(fieldcnt[i])
            << new QStandardItem(QString::number(tabcnt));

        QList<SQLdata> fieldlist = DB.TableFieldGet(dbtabe[i]);
        //增加字段
        //从1开始 去除默认的id
        for(int j = 1;j < fieldlist.size();j++){
            QList<QStandardItem *> childrow;
            Type type = fieldlist[j].second;
            QString fieldname = fieldlist[j].first,typestr;
            if(type == Int_Type) typestr = "整形";
            else if(type == Double_Type) typestr = "浮点型";
            else if(type == Char_Type) typestr = "字符型";
            else if(type == Bool_Type) typestr = "布尔型";
            else if(type == Date_Type) typestr = "时间性";
            childrow << new QStandardItem(fieldname)
                     << new QStandardItem() //这两个只是为了对齐
                     << new QStandardItem()
                     << new QStandardItem(typestr);
            row[0]->appendRow(childrow);
        }


        model->appendRow(row);
    }
    mgwid->ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
    mgwid->ui->treeView->setModel(model);
    mgwid->ui->treeView->header()->setHidden(false);
    personal_form->stackedWidget->addWidget(mgwid);
}

void Personal_MainWindow::ResetAll()
{
    currentID = 0;
    mgmtlist.clear();
    if(personal_form != nullptr)
    {
        delete personal_form;
        personal_form = new Ui::Personal_MainWindow;
        UiInit();
        UiConnectInit();
        qout << "PersonalMW Reset Complete!";
    }
}

void Personal_MainWindow::ShowUp()
{
    flwid->resize(1100,600);
    flwid->show();
}

Personal_MainWindow::~Personal_MainWindow()
{
    qout << "Personal_MainWindow closed";
    delete personal_form;
}
