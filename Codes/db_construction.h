#ifndef DB_CONSTRUCTION_H
#define DB_CONSTRUCTION_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTableView>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

#include "CustomDefine.h"

struct THEDBInfoSet{
    int port;
    QString dbname,user,passw;
};

class DB_Construction
{
public:
    DB_Construction();
    ~DB_Construction();
    THEDBInfoSet DBSet = {3306,"DBforCompetition","root","xyb110qq"};
    /* 以下xxxField的QStringList变量为预设的public变量，
     * 旨在方便查询一个表的所有字段，一般会作为其他函数中的FieldCon形参
     * 但FieldCon形参不一定所有用到都是下面的变量
     * 如果需要查询具体的某一个或某一些字段，那需要另外进行设置
     */
    QStringList loginField = {"logindb","account","password"};
    QStringList mgmtsysField = {"mgmtsysdb","account","sysname","uniquename","describle","tablecnt"};
    QStringList mgmtsysalltableField = {"mgmtsysalltabledb","DBtablename","uniquename","account",
                                        "管理系统名称","表名称","表描述","表字段数","表信息"};
    QSqlDatabase mainDB = QSqlDatabase::addDatabase("QMYSQL");
    QString ConnectError;

    bool DBInit(THEDBInfoSet dbinfo);
    void SelectTableDebugShow(QString tablename);
    void SQLDebugShow(QString SQLcode);
    /* 函数名称：TableOneDataFind
     * 描述：对输入的信息进行存在性检查，若数据存在则返回真，反之假，这里的条件限制位等于（=）
     * 效果：等效为SQL语句:SELECT A FROM B where x1 = y1 AND x2 = y2 ......;
     * 形参：field------上述语句中的A,查找的字段，若需要查找一个表的所有字段，则直接使用*
     *      InputData--SQLdata为一个pair型，first为数据内容，second为数据类型，
     *                 数据类型由枚举体Type决定，在传入函数之前，需要注明每条数据的类型
     *                 第0位表示表名称，Type类型为Null_Type
     *                 上述语句中的B(InputData[0])与yi，查找的条件值，SQL中的where xxx = InputData[i]
     *      Fieldcond--上述语句中的B(Fieldcond[0])与xi，查找的字段值，SQL中的where Fieldcond[i] = xxx
     *      Fieldcond InputData需要对应表一致才能够执行，它们的第0位都表示表名称
     * 其他：一定要按照MYSQL中表的字段顺序添加对应数据
     */
    bool TableOneDataFind(QString field,QList<SQLdata> InputData,QStringList Fieldcond);
    QStringList TableDataGet(QString field,QList<SQLdata> InputData,QStringList Fieldcond);
    QList<SQLdata> TableFieldGet(QString tabname);
    /* 函数名称：TableInsertOneData
     * 描述：在指定表中插入一行不为空数据
     * 效果：等效为SQL语句:INSERT INTO A(x1,x2...) values(y1,y1,...);
     * 形参：InputData--与上一个函数基本相同。
     *                 上述语句中的A(InputData[0].first)与yi，查找的条件值，SQL中的values(InputData[i].first,...)
     *      Fieldcond--上述语句中的A(Fieldcond[0])与xi，查找的字段值，SQL中的A(Fieldcond[i],...)
     *      Fieldcond InputData需要对应表一致才能够执行，它们的第0位都表示表名称
     * 其他：一定要按照MYSQL中表的字段顺序添加对应数据
     */
    bool TableInsertOneData(QList<SQLdata> InputData,QStringList Fieldcond);
    /* 函数名称：TableCreate
     * 描述：创建一个新的MySQL表
     * 效果：等效为SQL语句:CREATE TABLE NAME (name1 typeset1 ......)comment 'text';
     * 形参：name-----字段名称，SQL中的namei
     *      typeset--字段类型与设置(形如unique,unsigned等)typeseti
     *      name typeset需要对应表一致才能够执行，它们的第0位都表示表名称，第最后一位都表示comment注释内容
     */
    bool TableCreate(QStringList name,QStringList typeset);
    int TableDataCntGet(QString tabname);
    QSqlTableModel * DBToTableView(QObject * parent,QString tablename);
    QString TableDataSearch(QList<SQLdata> InputData,QStringList Fieldcond,QStringList eql);
private:
    bool SQLExecuteAndCheck(QSqlQuery *res,QString condition);
    void SqlQueryDebugInfo(QSqlQuery *res);
    void TableErrorDebugInfo(QSqlQuery *res);
};

#endif // DB_CONSTRUCTION_H
