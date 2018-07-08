
#include "PropertyNameLineEdit.hpp"
#include "MainWindow.hpp"
#include "Canvas.hpp"


PropertyNameLineEdit::PropertyNameLineEdit(QWidget *parent,
                    Canvas *canvas, QString name):
   QLineEdit(parent),
   m_canvas(canvas){
    setText(name);
}


PropertyNameLineEdit::PropertyNameLineEdit(QWidget *parent,
                    Canvas *canvas,
                    std::function<QString()> getter,
                    std::function<void(QString)> setter):
    QLineEdit(parent),
    m_canvas(canvas){
     setGetterSetter(getter,setter);
 }

void PropertyNameLineEdit::setGetterSetter(std::function<QString()> getter,
                                           std::function<void(QString)> setter){
    QObject::disconnect(m_connection);
    setText(getter());
    m_connection=connect(this,(&QLineEdit::textChanged),
                    [=](QString name){
                        setter(name);
                        m_canvas->repaint();
                    }
               );
}

void PropertyNameLineEdit::unlink(){
    setGetterSetter([=](){return text();},
            [=](QString){}
                );
}

PropertyNameLineEdit::~PropertyNameLineEdit(){

}
