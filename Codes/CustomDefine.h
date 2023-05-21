#ifndef CUSTOMDEFINE_H
#define CUSTOMDEFINE_H

#include <QPair>
#include <QString>
#include <windows.h>

#define qout qDebug()
#define btnclicked &QPushButton::clicked
#define sayhello qout<<"hello";
#define DeleteOnClose setAttribute(Qt::WA_DeleteOnClose,true);
#define RunTime_start LARGE_INTEGER t1, t2, tc;QueryPerformanceFrequency(&tc);QueryPerformanceCounter(&t1);
#define RunTime_end QueryPerformanceCounter(&t2);qout<<"\nTime Cost:"<<(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart<<"s"<<endl;

enum Type {
    Null_Type,Int_Type,Double_Type,Bool_Type,Date_Type,Char_Type,Json_Type
};

typedef QPair<QString,Type> SQLdata;

#endif // CUSTOMDEFINE_H
