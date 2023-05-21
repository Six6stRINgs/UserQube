#ifndef TABLE_WIDGET_H
#define TABLE_WIDGET_H

#include <QWidget>
#include "ui_tablewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class tablewidget;}
QT_END_NAMESPACE

class Table_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Table_Widget(QWidget *parent = nullptr):
        QWidget(parent),ui(new Ui::tablewidget)
    {
        ui->setupUi(this);
    }
    ~Table_Widget(){

    }
    Ui::tablewidget *ui;
};

#endif // TABLE_WIDGET_H
