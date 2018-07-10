#ifndef NETBOY_H
#define NETBOY_H
#include <QtNetwork>
#include <QObject>

class NetBoy : public QObject
{
    Q_OBJECT
public:
    explicit NetBoy(QObject *parent = nullptr);
    void hey();
    int newRoom(int x, int y);
    void updateRoomPos(int roomId,int x, int y);
signals:

public slots:

private:
    QString baseUrl;
    QNetworkRequest req;
    QNetworkAccessManager* manager;
    QNetworkReply* res;
};

#endif // NETBOY_H