#ifndef NODESERVERMANAGER_H
#define NODESERVERMANAGER_H

#include "netboy.h"
#include <QMessageBox>
#include <QObject>

class NodeServerManager : public QObject
{
    Q_OBJECT
public:
    explicit NodeServerManager(QObject *parent = nullptr);
    bool checkServer();

signals:

public slots:
    void kiilNode();

private:
    NetBoy nb;
    QProcess p;
    QString program;
    bool knockNode;
    bool goKnockNode();
    void propmtServerFail();
};

#endif // NODESERVERMANAGER_H

