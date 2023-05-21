#ifndef PUBLICSIGNAL_H
#define PUBLICSIGNAL_H

#include <QObject>
#include "CustomDefine.h"

class PublicSignal: public QObject{
    Q_OBJECT

signals:
    void login_successfully(QString name);
    void CallCreate(QString cre_account);
    void CallMgmtSystem(QList<SQLdata> mgmtname);
    void MW_NewInit();
};

#endif // PUBLICSIGNAL_H
