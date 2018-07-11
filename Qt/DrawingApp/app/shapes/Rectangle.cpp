#include "Rectangle.hpp"
#include <QPainter>
#include <QLabel>
Rectangle::Rectangle()
{
    setPosition(QPoint(10, 10));
    m_width = 150;
    m_height = 150;
}

Rectangle::~Rectangle()
{

}

void Rectangle::draw(QPainter *painter)
{
    QBrush brush(getFillColor());
    QPen pen(getLineColor());

    if (getLineThickness() == 0) pen.setStyle(Qt::NoPen);

    pen.setWidth(getLineThickness());


    //painter->setBrush();
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawRect(QRect(getPosition().x(),
                            getPosition().y(),
                            m_width, m_height));

    //给房间（矩形）标记
    painter->drawText(getPosition().x()+10,
                      getPosition().y()+15,m_name);
}

QRect Rectangle::getBoundary()
{
    int margin = 4;
    return QRect(getPosition().x() - margin,
                 getPosition().y() - margin,
                 m_width  + margin*2 + 1,
                 m_height + margin*2 + 1);
}

bool Rectangle::contains(int x, int y)
{
    return QRect(getPosition().x(),
                 getPosition().y(),
                 m_width, m_height).contains(x, y);
}
int Rectangle::getWidth() const
{
    return m_width;
}

void Rectangle::setWidth(int value)
{
    m_width = value;
}
int Rectangle::getHeight() const
{
    return m_height;
}

void Rectangle::setHeight(int value)
{
    m_height = value;
}



