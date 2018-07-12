#ifndef SIMULATION_H
#define SIMULATION_H
#include <QObject>
#include <QColor>
#include "Canvas.hpp"

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = nullptr,Canvas *canvas = nullptr);
    void setBackgroundColor(QColor val);
signals:

public slots:
    void startSimulate();
private:
Canvas *gbCanvas;
};

#endif // SIMULATION_H
