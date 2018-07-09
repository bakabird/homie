#pragma once

// author: rdd
#include <netboy.h>


class QEvent;
class QMouseEvent;
class QKeyEvent;
class Canvas;

class Tool
{
public:
    Tool(Canvas *canvas);
    ~Tool();

    bool handleEvent(QEvent *event);

    // author: rdd
    void setNetBoy(NetBoy* gb_nb);

protected:
    virtual void mousePress(QMouseEvent*) {}
    virtual void mouseMove(QMouseEvent*) {}
    virtual void mouseRelease(QMouseEvent*) {}
    virtual void keyPress(QKeyEvent*) {}

    Canvas *m_canvas;

    // author: rdd
    NetBoy* globalNetBoy;
};

