#include "login_widget.h"
#include "ui_loginUI.h"
#include "ui_DBsetWidget.h"

#include <QMovie>

extern DB_Construction DB;
extern PublicSignal pub_sig;

Login_Widget::Login_Widget(QWidget *parent) :
    QWidget(parent),
    login_Form(new Ui::loginUI),DB_Form(new Ui::DBsetWidget)
{
    qout << "Begin Login loading...";
    flwid->setWindowTitle("UserQube-登录界面");
    flwid->setWindowIcon(QIcon(":/icon/LOGO.png"));
    flwid_DB->setWindowTitle("UserQube-数据库测试界面");
    flwid_DB->setWindowIcon(QIcon(":/icon/LOGO.png"));
    ComOp::SetNoLogo(flwid);
    ComOp::setFrameLess(flwid,this);
    ComOp::setFrameLess(flwid_DB,DB_Wiget);

    login_Form->setupUi(this);
    DB_Form->setupUi(DB_Wiget);
    login_Form->difficultT_T->setHidden(true);

    DB_WidgetInit();

    QMovie *photo_gif = new QMovie(":/icon/LOGO-2.png");
    login_Form->photo_lab->setMovie(photo_gif);
    photo_gif->start();

    ConnectInit();
    ShowUp(flwid,QSize(450,700));
}

void Login_Widget::ConnectInit()
{
    //和槽信号初始化
    connect(login_Form->quit_btn,btnclicked,flwid,&Login_Widget::close);
    connect(login_Form->login_btn,btnclicked,this,&Login_Widget::LoginCheck);
    connect(login_Form->change_btn,btnclicked,this,&Login_Widget::AccountCreate);
    connect(login_Form->passw_view,btnclicked,this,[=](){
        Password_viewChange(login_Form->passw_view,login_Form->passw_input);
    });
    connect(login_Form->DBset_btn,btnclicked,this,[=](){
        ShowUp(flwid_DB,QSize(400,500));
    });
}

void Login_Widget::DB_WidgetInit()
{
    DB_Form->Account_line->setLabel("输入数据库用户");
    DB_Form->Passw_line->setLabel("输入密码");

    connect(DB_Form->passw_view,btnclicked,flwid_DB,[=](){
        Password_viewChange(DB_Form->passw_view,DB_Form->Passw_line);
    });
    connect(DB_Form->Test_btn,btnclicked,flwid_DB,[=](){
        if(!NotNullCheck(DB_Form->Account_line,DB_Form->Passw_line)) return ;
        if(DBConnectTest())
            QMessageBox::information(flwid_DB,"提示","连接测试成功!");
        else
            QMessageBox::critical(flwid_DB,"警告","连接测试失败!\n错误信息：" + DB.ConnectError);
    });

    connect(DB_Form->no_btn,btnclicked,flwid_DB,&QWidget::hide);
    connect(DB_Form->yes_btn,btnclicked,flwid_DB,[=](){
        if(!NotNullCheck(DB_Form->Account_line,DB_Form->Passw_line)) return ;
        if(DBConnectTest()){
            DB.DBSet.user = DB_Form->Account_line->text();
            DB.DBSet.passw = DB_Form->Passw_line->text();
            QMessageBox::information(flwid_DB,"提示","设置成功");
            flwid_DB->hide();
            emit pub_sig.MW_NewInit();
        } else
            QMessageBox::critical(flwid_DB,"警告","连接失败!\n错误信息：" + DB.ConnectError);
    });
}

bool Login_Widget::DBConnectTest()
{
    THEDBInfoSet DBTest = DB.DBSet;
    DBTest.user = DB_Form->Account_line->text();
    DBTest.passw = DB_Form->Passw_line->text();
    return DB.DBInit(DBTest);
}

void Login_Widget::Password_viewChange(QPushButton *btn,QLineEdit *line)
{
    //修改密码的显示状态
    QString st = btn->text();
    if(st == "◈") {
        line->setEchoMode(QLineEdit::Normal);
        btn->setText("◇");
    } else {
        line->setEchoMode(QLineEdit::Password);
        btn->setText("◈");
    }
}

void Login_Widget::LoginCheck()
{
    if(!DB.mainDB.isOpen()){
        QMessageBox::critical(this,"警告","数据库无法连接");
        return ;
    }
    if(!NotNullCheck(login_Form->account_input,login_Form->passw_input)) return ;
    QList<SQLdata> info = {{"logindb",Null_Type}};
    info.append({login_Form->account_input->text(),Char_Type});
    info.append({login_Form->passw_input->text(),Char_Type});

    //搜索信息是否存在
    if(DB.TableOneDataFind("1",info,DB.loginField))
    {
        qout << "Login Successfully";
        //发出登录信号，并将登陆用户名进行发送
        emit pub_sig.login_successfully(info[1].first);
        flwid->hide();
    }
    else
        QMessageBox::critical(this,"错误","信息错误");
}

void Login_Widget::AccountCreate()
{
    if(!DB.mainDB.isOpen()){
        QMessageBox::critical(this,"警告","数据库无法连接");
        return ;
    }
    if(!NotNullCheck(login_Form->account_input,login_Form->passw_input)) return ;
    QList<SQLdata> newinfo = {{"logindb",Null_Type}};
    //FieldCon作为查找用户名是否存在而设置的一个变量
    QStringList FieldCon = {"logindb","account"};
    newinfo.append({login_Form->account_input->text(),Char_Type});

    //创建的用户名必须是数据库中不存在的
    if(!DB.TableOneDataFind("account",newinfo,FieldCon))
    {
        newinfo.append({login_Form->passw_input->text(),Char_Type});
        if(DB.TableInsertOneData(newinfo,DB.loginField)){
            QMessageBox::information(this,"完成","创建用户成功");
        } else
            QMessageBox::critical(this,"错误","创建用户失败");

    } else
       QMessageBox::critical(this,"错误","设置的用户名已存在");
}

bool Login_Widget::NotNullCheck(QLineEdit * acc,QLineEdit * passw)
{
    //空信息检查
    if(passw->text().isEmpty() || acc->text().isEmpty())
    {
        QMessageBox::critical(this,"错误","存在空信息");
        return false;
    }
    return true;
}

void Login_Widget::ShowUp(framelessWidget * wid,QSize size)
{
    wid->setFixedSize(size);
    ComOp::setNotMax(wid);
    wid->show();
}

Login_Widget::~Login_Widget()
{
    qout << "LoginGUI closed";
    delete login_Form;
}
