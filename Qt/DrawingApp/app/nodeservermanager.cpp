#include "nodeservermanager.h"

NodeServerManager::NodeServerManager(QObject *parent) : QObject(parent)
{
    // 改变当前执行路径
    QDir::setCurrent(QCoreApplication::applicationDirPath().append("/server/"));
    // 需要在对应的路径放置好服务器才能正常运行
    #ifdef Q_OS_WIN
    program = "./node_win.exe ./development.js";
    #endif
    #ifdef Q_OS_MAC
    program = "./node_mac development.js";
    #endif
    p.setProcessChannelMode(QProcess :: MergedChannels);
}

bool NodeServerManager::checkServer()
{
    // 确认是否有已经运行的服务器
    if(nb.hey()){
        auto answer = QMessageBox::question(NULL, "确认", "已有服务器启动，是否发送数据库刷新请求？",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(answer == QMessageBox::Yes){
            // 刷新服务器
            nb.refreshDB();
        }
        return true;
    }else{
        // 程序自己启动服务器
        return goKnockNode();
    };
}

bool NodeServerManager::goKnockNode()
{
    bool success = false;

    knockNode = true;
    QEventLoop eventLoop;


    QObject::connect(&p, &QProcess::started, &eventLoop, &QEventLoop::quit);
    QObject::connect(&p, &QProcess::errorOccurred, &eventLoop, &QEventLoop::quit);

    qDebug() << "启动服务器...";
    p.start(program);
    eventLoop.exec();

    QObject::disconnect(&p, &QProcess::errorOccurred, &eventLoop, &QEventLoop::quit);

    // 运行超过5秒认为服务器成功运行
    if(p.state() == QProcess::Running){
        if(p.waitForFinished(5000)){
            QByteArray result = p.readAll();
            qDebug() << "服务器的执行日志如下：";
            qDebug() << result;
            qDebug() << "服务器启动失败了！";
        }else{
            qDebug() << "服务器启动成功了！";
            success = true;
        }
    }

    if(!success){
        propmtServerFail();
        return false;
    }else{
        return true;
    }
};

void NodeServerManager::propmtServerFail()
{
    QString title = QString("执行失败");
    QString tips = QString("程序主动开启服务器失败了，请确认服务器是否在合适的路径下，或自行启动启动服务器。\n启动服务器命令的执行目录是\n%1\n命令是\n%2\n").arg(QDir::currentPath()).arg(program);
    auto answer = QMessageBox::critical(NULL, title,tips,QMessageBox::StandardButtons(QMessageBox::Yes),QMessageBox::Yes);
    if(answer == QMessageBox::Yes) return;
}

void NodeServerManager::kiilNode()
{
    if(p.state() != QProcess::NotRunning) {
        p.close();
        p.kill();
        p.waitForFinished();
    }
}



