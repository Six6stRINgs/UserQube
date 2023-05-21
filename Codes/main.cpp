#include <QApplication>
#include "systemcore.h"

DB_Construction DB;
PublicSignal pub_sig;

int main(int argc, char *argv[])
{
    RunTime_start
    QApplication a(argc, argv);
    SystemCore application;
    RunTime_end
    return a.exec();
}
