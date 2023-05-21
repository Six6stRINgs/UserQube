#ifndef FIELD_WIDGET_H
#define FIELD_WIDGET_H

#include <QWidget>
#include <QDebug>
#include "ui_fieldwidget.h"
#include "CustomDefine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fieldwidget;}
QT_END_NAMESPACE

class Field_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Field_Widget(QWidget *parent = nullptr):
        QWidget(parent),ui(new Ui::fieldwidget)
    {
        ui->setupUi(this);
        ui->stackedWidget->setCurrentIndex(0);
    }
    ~Field_Widget(){
        //qout << "field_widget deleted";
    }
    Ui::fieldwidget *ui;
};



#endif // FIELD_WIDGET_H
