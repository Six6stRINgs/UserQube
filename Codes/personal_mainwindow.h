#ifndef Personal_MainWindow_H
#define Personal_MainWindow_H

#include <QMainWindow>
#include <QDebug>

#include "login_widget.h"
#include "PublicSignal.h"
#include "CustomClass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Personal_MainWindow; }
QT_END_NAMESPACE

class Personal_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Personal_MainWindow(QWidget *parent = nullptr);
    ~Personal_MainWindow();

    QString account = "admin";
private slots:
    void LoginConnect(QString name);
    void CallCreateWindow();
private:
    int currentID = 0;
    QList<QList<SQLdata>> mgmtlist;

    void ConnectInit();
    void UiConnectInit();
    void UiInit();
    void UiTreeTableInit(QString mgmtname,QString mgmtdes,QList<SQLdata> mgmtinfo);
    inline void ResetAll();
    void ShowUp();
    bool firstLoad = true;
    framelessWidget * flwid = new framelessWidget;
    Ui::Personal_MainWindow *personal_form;
};

#endif // Personal_MainWindow_H
