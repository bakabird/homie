#ifndef PROPERTYNAMELINEEDIT_HPP
#define PROPERTYNAMELINEEDIT_HPP

#include <QLineEdit>
#include <functional>
class Canvas;

class PropertyNameLineEdit:public QLineEdit{

public:
    PropertyNameLineEdit(QWidget *parent,
                        Canvas *canvas, QString name);

    PropertyNameLineEdit(QWidget *parent,
                        Canvas *canvas,
                        std::function<QString()> getter,
                        std::function<void(QString)> setter);

    void setGetterSetter(std::function<QString()> getter,
                         std::function<void(QString)> setter);

    void unlink();
    ~PropertyNameLineEdit();

private:
    QMetaObject::Connection m_connection;
    Canvas *m_canvas;

};


#endif // PROPERTYNAMELINEEDIT_HPP
