#ifndef MGMTINFO_WIDGET_H
#define MGMTINFO_WIDGET_H

#include <QWidget>
#include "ui_mgmtinfowidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mgmtinfowidget;}
QT_END_NAMESPACE

class MgmtInfo_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit MgmtInfo_Widget(QWidget *parent = nullptr):
        QWidget(parent),ui(new Ui::mgmtinfowidget)
    {
        ui->setupUi(this);
    }
    ~MgmtInfo_Widget(){

    }

    Ui::mgmtinfowidget * ui;
};

#endif // MGMTINFO_WIDGET_H
