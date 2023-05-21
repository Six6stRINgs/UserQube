#ifndef CUSTOMCLASS_H
#define CUSTOMCLASS_H

#include "table_widget.h"
#include "field_widget.h"
#include "mgmtinfo_widget.h"
#include "myMaterialButton.h"
#include "framelessWidget.h"
#include "DateTimeDelegate.h"
#include "BoolDelegate.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTimeEdit>
#include <windows.h>

class CommonOperation
{
public:

    static bool isNumeric(const QString &str) {
        QRegExp re("^-?\\d*\\.?\\d+$");
        return re.exactMatch(str);
    }
    static void setFrameLess(framelessWidget * flwid,QWidget * widget){
        QHBoxLayout * layout = new QHBoxLayout();
        layout->addWidget(widget);
        QWidget * mainw = flwid->findChild<QWidget *>("mainDisplayWidget");

        flwid->setWindowFlag(Qt::FramelessWindowHint);
        flwid->setAttribute(Qt::WA_TranslucentBackground);
        mainw->setLayout(layout);
    }
    static void setNotMax(framelessWidget * flwid)
    {
        QPushButton * maxbtn = flwid->findChild<QPushButton *>("Button_max"); //窗口是固定的！
        maxbtn->setDisabled(true);
    }
    static QString TimeEditSetting(QJsonObject obj,QString name,QDateTimeEdit *timeset = nullptr){
        QString timedisplay;
        QJsonArray timeArray = obj[name].toArray();
        if(timeArray[0] == 1) timedisplay += "yyyy";
        if(timeArray[1] == 1) timedisplay += timedisplay.isNull() ? "MM" : "/MM";
        if(timeArray[2] == 1) timedisplay += timedisplay.isNull() ? "dd" : "/dd";
        if(timeArray[3] == 1) timedisplay += timedisplay.isNull() ? "HH:mm" : " HH:mm";

        if(timeset != nullptr)
        {
            QDateTime dateTime = timeset->dateTime();
            int year = dateTime.date().year();
            int mon = dateTime.date().month();
            int day = dateTime.date().day();
            int hour = dateTime.time().hour();
            int min = dateTime.time().minute();
            //int sec = dateTime.time().second();
            dateTime.setTime(QTime(hour,min,00));  //秒默认取消
            if (timeArray[0] == 0) dateTime.setDate(QDate(1900,mon,day));
            if (timeArray[1] == 0) dateTime.setDate(QDate(year,1,day));
            if (timeArray[2] == 0) dateTime.setDate(QDate(year,mon, 1));
            if (timeArray[3] == 0) dateTime.setTime(QTime(0, 0, 0));
            timeset->setDateTime(dateTime);
        }
        return timedisplay;
    }
    static void SetNoLogo(framelessWidget * flwid)
    {
        QPushButton * logo = flwid->findChild<QPushButton *>("logo");
        logo->setHidden(true);
    }
};

typedef CommonOperation ComOp;

#endif // CUSTOMCLASS_H
