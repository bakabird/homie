#ifndef SERVER_H
#define SERVER_H
#include <QColor>
#include <QPoint>
#include "Canvas.hpp"
#include "VisualEntity.hpp"

class Server{
public:
    Sever();
    void setFillColor(VisualEntity *Entity, QColor &color);
    QPoint getPosition();

private:
    Canvas *mycanvas;
}

#endif // SERVER_H
