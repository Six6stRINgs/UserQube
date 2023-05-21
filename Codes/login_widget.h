#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QResizeEvent>
#include "qtmaterialdialog.h"

#include "db_construction.h"
#include "PublicSignal.h"
#include "CustomClass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class loginUI;class DBsetWidget; }
QT_END_NAMESPACE

class Login_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Login_Widget(QWidget *parent = nullptr);
    ~Login_Widget();

private slots:
    void LoginCheck();  //登录信息检查
    void AccountCreate(); //增加用户信息
private:
    void DB_WidgetInit();
    bool DBConnectTest(); //数据库连接检查
    void Password_viewChange(QPushButton *btn,QLineEdit *line); //密码状态修改（可视/不可视）
    bool NotNullCheck(QLineEdit * acc,QLineEdit * passw);
    void ConnectInit();
    void ShowUp(framelessWidget * wid,QSize size);

    framelessWidget * flwid = new framelessWidget;
    framelessWidget * flwid_DB = new framelessWidget;
    QWidget * DB_Wiget = new QWidget;
    Ui::loginUI *login_Form;
    Ui::DBsetWidget *DB_Form;
};

#endif // LOGINGUI_H
