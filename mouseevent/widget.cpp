#include "widget.h"
#include "ui_widget.h"

#include <QCursor>
#include <QMouseEvent>
#include <QWheelEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset_ = event->globalPosition().toPoint() - pos();
    } else if(event->button() == Qt::RightButton) {
        QCursor cursor(QPixmap(":/images/resources/images/mouse.png").scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        QApplication::setOverrideCursor(cursor);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (windowState() == Qt::WindowFullScreen) {
            setWindowState(Qt::WindowNoState);
        } else {
            setWindowState(Qt::WindowFullScreen);
        }
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        this->move(event->globalPosition().toPoint() - offset_);
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        ui->textEdit->zoomIn();
    } else {
        ui->textEdit->zoomOut();
    }
}

