#ifndef MGMT_MAINWINDOW_H
#define MGMT_MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QDebug>
#include <QDateTimeEdit>
#include <QDateTime>
#include <QButtonGroup>
#include <QSet>

#include <QtCharts>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>


#include "db_construction.h"
#include "PublicSignal.h"
#include "CustomClass.h"
#include "CustomDefine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mgmtsystem; } 
QT_END_NAMESPACE

using namespace QtCharts;

class Mgmt_MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mgmt_MainWindow(QWidget *parent = nullptr);
    ~Mgmt_MainWindow();
signals:

private slots:
    void MgmtInfoInit(QList<SQLdata> mgmtname);
    void ShowUp();
    void ViewUpdateCheck(const QModelIndex &index);
    void SearchClose();
    void ChartSetting();
    //管理系统经典操作~~ 增删改查
    void AddData();
    void EditData();
    void SearchData();
    void DelData();
private:

    //用于fieldConstrcutToWidget函数
    enum BtnCommandType{
        Btn_Add,Btn_Search,Btn_Chart
    };

    QString account = "Admin";
    QString mgmt_name = "Test_mgmt";
    QList<QJsonObject> jsonlist;
    QList<QSqlTableModel *> modellist;
    QList<QTableView *> viewlist;
    QList<QWidget *> widgetlist;  //控件list，用于增加与查找中定位控件
    QSet<int> dis_widgetset;
    QList<bool> searchMode;

    QVariant oldValue;
    int currentID = 0;

    void ConnectInit();
    void UiInit();
    void UiConnectInit(); //由于Ui重新申请空间后connect被清除，所以需要进行重新建立
    bool fieldConstrcutToWidget(QList<SQLdata> field,QWidget * wid,QFormLayout * lay,
                                BtnCommandType btntype);
    //确认、取消按钮布局
    QHBoxLayout* confirmBtnLayout(QPushButton * yes,QPushButton * no);
    //获得当前表所对应的所有字段（但除去第一个默认字段
    QHBoxLayout* disBtnSetting(QList<QWidget*> wid,int cnt);
    //从某一个字段获取其中的所有数据
    QStringList getDataFromField(QString fieldname);
    //从某一字段获取它的类型
    Type getTypeFromField(QString fieldname);
    inline QList<SQLdata> getField();
    //从Widget控件中获取所有输入的内容（用于增加、查找、修改等操作）
    inline QList<SQLdata> getFieldinput(QList<SQLdata> field);
    //获得当前表在MySQL数据库中的名称
    inline QString getDBtablename();
    //从QList<SQLdata>变量中获取其first，也就是字段名，都存入在返回的QStringList
    inline QStringList getFieldNameInSQLDataType(QList<SQLdata> field);
    //更新QTableView中的表数据，并将modelllist与viewlist进行赋值更新
    inline void ResetAll(); //在执行DataUpdate前，需要进行数据重置
    bool firstload = true; //第一次加载时，不需要进行数据重置(ResetAll函数)

    void DataUpdate(QStringList dbtab);

    void showChart(const QStringList &xData, const QStringList &yData,
                   const Type xtype,const Type ytype);

    framelessWidget * flwid = new framelessWidget;
    Ui::mgmtsystem *mgmt_form;
};

#endif // MGMT_MAINWINDOW_H
