#include "db_construction.h"

#include <QTextCodec>

DB_Construction::DB_Construction()
{
    qout << "Begin DB loading...";
    DBInit(DBSet);
    //SelectTableDebugShow("logindb");
}


bool DB_Construction::DBInit(THEDBInfoSet dbinfo)
{
    if(mainDB.isOpen()) mainDB.close();
    mainDB.setPort(dbinfo.port);
    mainDB.setDatabaseName(dbinfo.dbname);
    mainDB.setUserName(dbinfo.user);
    mainDB.setPassword(dbinfo.passw);

    //中文表会出现问题，所以需要把编码进行设置
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    mainDB.exec("set NAMES UTF8");

    if(!mainDB.open()) {
        qout << "DB Open Failed!" << endl;
        qout << mainDB.lastError().text() << endl;
        ConnectError = mainDB.lastError().text();
        if(mainDB.isOpen()) mainDB.close();
        return false;
    }
    else qout << "DB Open successfully!" << endl;
    return true;
}

bool DB_Construction::TableOneDataFind(QString field,QList<SQLdata> InputData,QStringList Fieldcond)
{
    //InputData与Field的第0位为标识码，表示具体的某一个表
    if(InputData.size() != Fieldcond.size() || InputData[0].first != Fieldcond[0]){
        qout << "Info check Error";
        qout << "InputData: " << InputData;
        qout << "Fieldcond: " << Fieldcond;
        return false;
    }
    QString condition = "SELECT " + field +  " FROM " + Fieldcond[0];
    if(Fieldcond.size() > 1) condition += " WHERE ";
    for(int i = 1;i < Fieldcond.size();i++){
        if(i != Fieldcond.size() - 1){
            if(InputData[i].second == Char_Type ||
               InputData[i].second == Json_Type || InputData[i].second == Date_Type)
                //字符型，JSON型需要加引号
                condition += QString("%1 = '%2' AND ").arg(Fieldcond[i]).arg(InputData[i].first);
            else
                condition += QString("%1 = %2 AND ").arg(Fieldcond[i]).arg(InputData[i].first);
        }
        else{
            if(InputData[i].second == Char_Type ||
               InputData[i].second == Json_Type || InputData[i].second == Date_Type)
                condition += QString("%1 = '%2' LIMIT 1").arg(Fieldcond[i]).arg(InputData[i].first);
            else
                condition += QString("%1 = %2 LIMIT 1").arg(Fieldcond[i]).arg(InputData[i].first);
        }
    }
    //执行SQL语句并进行有效性检测
    QSqlQuery res(mainDB);
    if(!SQLExecuteAndCheck(&res,condition)) return false;
    res.next();
    if(res.isValid()) return true;
    else {
        qout << "Not Found";
        TableErrorDebugInfo(&res);
        return false;
    }
}

QStringList DB_Construction::TableDataGet(QString field, QList<SQLdata> InputData,QStringList Fieldcond)
{
    QStringList data;
    //InputData与Field的第0位为标识码，表示具体的某一个表
    if(InputData.size() != Fieldcond.size() || InputData[0].first != Fieldcond[0]){
        qout << "Info check Error";
        qout << "InputData: " << InputData;
        qout << "Fieldcond: " << Fieldcond;
        return data;
    }
    QString condition = "SELECT " + field +  " FROM " + Fieldcond[0];
    if(Fieldcond.size() > 1) condition += " WHERE ";
    for(int i = 1;i < Fieldcond.size();i++)
    {
        if(InputData[i].second == Char_Type ||
           InputData[i].second == Json_Type || InputData[i].second == Date_Type)
            //字符型，JSON型需要加引号
            condition += QString("%1 = '%2'").arg(Fieldcond[i]).arg(InputData[i].first);
        else
            condition += QString("%1 = %2").arg(Fieldcond[i]).arg(InputData[i].first);
        if(i != Fieldcond.size() - 1) condition += " AND ";
    }
    //执行SQL语句并进行有效性检测
    QSqlQuery res(mainDB);
    if(!SQLExecuteAndCheck(&res,condition)) return data;
    while(res.next()) {
        if(res.isValid()) {
            QSqlRecord record = res.record();
            for(int i = 0;i < record.count();i++)
                data.append(record.value(i).toString());
        } else {
            TableErrorDebugInfo(&res);
        }
    }
    return data;
}

QList<SQLdata> DB_Construction::TableFieldGet(QString tabname)
{
    QList<SQLdata> field;
    QSqlQuery res(mainDB);
    if(!SQLExecuteAndCheck(&res,"SHOW COLUMNS FROM " + tabname)) return field;
    while (res.next())
    {
        //value(0)为字段名称 value(1)为字段类型
        Type type;
        if(res.value(1).toString() == "tinyint(1)") type = Bool_Type;
        else if(res.value(1).toString().contains("int")) type = Int_Type;
        else if(res.value(1).toString().contains("double")) type = Double_Type;
        else if(res.value(1).toString().contains("date")) type = Date_Type;
        else if(res.value(1).toString().contains("char")) type = Char_Type;
        else if(res.value(1).toString().contains("json")) type = Json_Type;
        field.append({res.value(0).toString(),type});
    }
    return field;
}

bool DB_Construction::TableInsertOneData(QList<SQLdata> InputData,QStringList Fieldcond)
{
    if(InputData.size() != Fieldcond.size() || InputData[0].first != Fieldcond[0]){
        qout << "Info check Error";
        qout << "InputData: " << InputData;
        qout << "Fieldcond: " << Fieldcond;
        return false;
    }
    //第0为作为表的标识码与验证码
    QString condition = "INSERT INTO " + Fieldcond[0] + " (";
    for(int i = 1;i < Fieldcond.size();i++)
    {
        condition += Fieldcond[i];
        if(i != Fieldcond.size() - 1) condition += ",";
        else condition += ")";
    }
    condition += "values(";
    for(int i = 1;i < InputData.size();i++)
    {
        if(InputData[i].second == Char_Type ||
           InputData[i].second == Json_Type || InputData[i].second == Date_Type)
            condition += "'" + InputData[i].first + "'";
        else
            condition += InputData[i].first;
        if(i != InputData.size() - 1) condition += ",";
        else condition += ")";
    }
    //执行SQL语句并进行有效性检测
    QSqlQuery res(mainDB);
    return SQLExecuteAndCheck(&res,condition);
}

bool DB_Construction::TableCreate(QStringList name,QStringList typeset)
{
    //name与typeset的第一位与最后一位比较特殊，它们的内容是相同的
    if(name.size() != typeset.size() || name[0] != typeset[0]){
        qout << "Info check Error";
        return false;
    }
    QString condition = "CREATE TABLE " + name[0] + " (";
    //到倒数第二个信息，最后一个为表的comment
    for(int i = 1;i < typeset.size() - 1;i++)
    {
        condition += QString("%1 %2").arg(name[i]).arg(typeset[i]);
        if(i != typeset.size() - 2)//这里需要-2
            condition += ",";
    }
    condition += ")comment '" + typeset.back() + "';";
    //执行SQL语句并进行有效性检测
    QSqlQuery res(mainDB);
    return SQLExecuteAndCheck(&res,condition);
}

QString DB_Construction::TableDataSearch(QList<SQLdata> InputData, QStringList Fieldcond, QStringList eql)
{
    QString condition;
    if(InputData[0].first != Fieldcond[0] || InputData.size() != Fieldcond.size()){
        qout << "Info check Error";
        qout << "InputData: " << InputData;
        qout << "Fieldcond: " << Fieldcond;
        return condition;
    }

    for(int i = 1;i < InputData.size();i++)
    {
        //%1为字段名 %2为运算符 %3为值
        if(InputData[i].second == Char_Type ||
           InputData[i].second == Json_Type || InputData[i].second == Date_Type)
            condition += QString("%1 %2 '%3' ").arg(Fieldcond[i]).arg(eql[i]).arg(InputData[i].first);
        else
            condition += QString("%1 %2 %3 ").arg(Fieldcond[i]).arg(eql[i]).arg(InputData[i].first);
        //目前只用AND连接符，其他例如OR的需要比较复杂的控件以实现
        if(i != InputData.size() - 1)
            condition += " AND ";
    }

    return condition;
}

QSqlTableModel* DB_Construction::DBToTableView(QObject * parent,QString tablename)
{
    //傻逼QT
    QSqlTableModel *model = new QSqlTableModel(parent,mainDB);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable(tablename);

    if(model->select()) qout << "model finded" << endl;
    else qout << model->lastError() << endl;

    //首先获得所有字段
    QList<SQLdata> field = TableFieldGet(tablename);
    for(int i = 0;i < field.size();i++)
        model->setHeaderData(i, Qt::Horizontal,field[i].first);
    qout << field;
    return model;
}

int DB_Construction::TableDataCntGet(QString tabname)
{
    QString conditon = "SELECT COUNT(*) FROM " + tabname;
    QSqlQuery res(mainDB);
    SQLExecuteAndCheck(&res,conditon);
    res.next();
    int cnt = res.value(0).toInt();
    qout << "Table " + tabname + " DataCnt:" << cnt;
    return cnt;
}


void DB_Construction::SelectTableDebugShow(QString tablename)
{
    QSqlQuery res = mainDB.exec("SELECT * FROM " + tablename);
    qout << "Showing the data from " + tablename;
    SqlQueryDebugInfo(&res);
}

void DB_Construction::SQLDebugShow(QString SQLcode)
{
    QSqlQuery res = mainDB.exec(SQLcode);
    qout << "Execute SQL Code: " + SQLcode;
    SqlQueryDebugInfo(&res);
}

void DB_Construction::SqlQueryDebugInfo(QSqlQuery *res)
{
    while(res->next()) {
        if(res->isValid()) {
            QSqlRecord record = res->record();
            for(int i = 0;i < record.count();i++)
                qout.noquote().nospace() << "Value " << i << ": " << qSetFieldWidth(10) << left
                     << record.fieldName(i) << record.value(i);
            qout; //空一行
        } else
            TableErrorDebugInfo(res);
    }
}

bool DB_Construction::SQLExecuteAndCheck(QSqlQuery *res, QString condition)
{
    qout << condition;
    if(res->exec(condition)){
        qout << "execute successfully!";
        return true;
    } else {
        TableErrorDebugInfo(res);
        return false;
    }
}

void DB_Construction::TableErrorDebugInfo(QSqlQuery *res)
{
    qout << "Tabel Error.The Info:";
    qout << res->lastError().text() << endl;
}

DB_Construction::~DB_Construction()
{
    mainDB.close();
    qout << "DB closed";
}
