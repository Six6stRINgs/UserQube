#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

#include "personal_mainwindow.h"
#include "create_mainwindow.h"
#include "mgmt_mainwindow.h"
#include "login_widget.h"
#include "PublicSignal.h"
#include "db_construction.h"
#include <QObject>

class SystemCore : public QObject
{
public:
    SystemCore();
    ~SystemCore();

private:
    //只有在数据库加载成功之后才会new
    void BeginLoad();

    Login_Widget * login_wid = nullptr;
    Personal_MainWindow * person_main = nullptr;
    Create_MainWindow * create_main = nullptr;
    Mgmt_MainWindow * mgmt_main = nullptr;
};

#endif // SYSTEMCORE_H
