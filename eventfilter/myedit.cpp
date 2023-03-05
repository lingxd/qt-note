#include "myedit.h"

#include <QDebug>
#include <QKeyEvent>

MyEdit::MyEdit(QWidget *parent) : QLineEdit(parent)
{

}

MyEdit::~MyEdit()
{

}

void MyEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("my edit is press");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}

bool MyEdit::event(QEvent *pevent)
{
    if (pevent->type() == QEvent::KeyPress) {
        qDebug() << tr("my edit event");
    }

    return QLineEdit::event(pevent);
}
