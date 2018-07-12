#ifndef NETBOY_H
#define NETBOY_H
#include <QtNetwork>
#include <QObject>
#include <QString>

class NetBoy : public QObject
{
    Q_OBJECT
public:
    explicit NetBoy(QObject *parent = nullptr);
    void hey();
    void refreshDB();
    int newRoom(int x, int y);
    void updateRoomPos(int roomId,int x, int y);
    void changeRoomName(int roomId, QString roomName);
    int switchMode(int aimMode);
    QJsonArray allLightsSta();
signals:

public slots:

private:
    QString baseUrl;
    QNetworkRequest req;
    QNetworkAccessManager* manager;
    QNetworkReply* res;
};

#endif // NETBOY_H
