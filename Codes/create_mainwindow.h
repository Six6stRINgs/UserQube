#ifndef CREATE_MAINWINDOW_H
#define CREATE_MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStringList>
#include <QStackedWidget>
#include <QMessageBox>
#include <QTreeWidget>

#include "db_construction.h"
#include "PublicSignal.h"
#include "CustomClass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Create_MainWindow; }
QT_END_NAMESPACE

struct cre_table{
    QList<Field_Widget *> field;
    QWidget * table;
};

class Create_MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Create_MainWindow(QWidget *parent = nullptr);
    ~Create_MainWindow();

    QString account = "admin"; //默认为admin用户
    QList<SQLdata> mgmtname;
    int table_cnt = 0;


    QList<cre_table> table_list;
signals:

private slots:
    void ShowUp(QString cre_account);
    void NewField_create(); //在对应表中添加新字段
    void DelField_Last();   //在对应表中删除最后的字段
    void Table_creat();
    void Table_del();
    void InfoRead();
private:
    //左边的"管理系统设置"总列表
    QTreeWidgetItem * top = new QTreeWidgetItem;

    bool infoCollect(QString user,cre_table tab);
    bool ALLNotNullCheck();
    bool fieldwig_NotNullCheck(Field_Widget *wid);
    void ConnectInit();
    void TreeInit();
    QList<SQLdata> get_mgmtsysBaseInfo();
    framelessWidget * flwid = new framelessWidget;
    Ui::Create_MainWindow *create_form;
};

#endif // CREATE_MAINWINDOW_H
