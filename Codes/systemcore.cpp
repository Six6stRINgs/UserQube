#include "systemcore.h"
#include "qtmaterialdialog.h"

extern DB_Construction DB;
extern PublicSignal pub_sig;

SystemCore::SystemCore()
{
    qout << "Begin System loading...";
    BeginLoad();
}

void SystemCore::BeginLoad()
{
    login_wid = new Login_Widget;
    if(DB.mainDB.isOpen()){
        person_main = new Personal_MainWindow;
        create_main = new Create_MainWindow;
        mgmt_main = new Mgmt_MainWindow;
    } else {
        QMessageBox::critical(login_wid,"警告","本地数据库连接失败，请重新设置\n错误信息：" + DB.ConnectError);
    }

    connect(&pub_sig,&PublicSignal::MW_NewInit,this,[=](){
        if(person_main == nullptr){
            person_main = new Personal_MainWindow;
            qout << "person_main New Complete";
        }
        if(create_main == nullptr){
            create_main = new Create_MainWindow;
            qout << "create_main New Complete";
        }
        if(mgmt_main == nullptr){
            mgmt_main = new Mgmt_MainWindow;
            qout << "mgmt_main New Complete";
        }
    });
}

SystemCore::~SystemCore()
{
    delete login_wid;
    delete person_main;
    delete create_main;
    delete mgmt_main;
    qout << "System closed";
}
