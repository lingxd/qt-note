#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QWheelEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    my_edit_ = new MyEdit(this);
    my_edit_->move(100, 100);
    my_edit_->installEventFilter(this);
    ui->textEdit->installEventFilter(this);
    ui->spinBox->installEventFilter(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("my widget is press") << "\n";
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == my_edit_) {
        if(event->type() == QEvent::KeyPress) {
            qDebug() << tr("widget event filter catch line_edit");
            return false;
        }
    }

    if(watched == ui->textEdit) {
        if(event->type() == QEvent::Wheel) {
            auto wheelevent = static_cast<QWheelEvent*>(event);
            if(wheelevent->angleDelta().y() > 0) {
                qDebug() << "catch wheel event delta > 0" << "\n";
                ui->textEdit->zoomIn();
            }
            if(wheelevent->angleDelta().y() < 0) {
                qDebug() << "catch wheel event delta < 0" << "\n";
                ui->textEdit->zoomOut();
            }
            return true;
        }
        return false;
    }

    if(watched == ui->spinBox) {
        if(event->type() == QEvent::KeyPress) {
            auto keyevent = static_cast<QKeyEvent*>(event);
            if(keyevent->key() == Qt::Key_Space) {
                ui->spinBox->setValue(0);
                return true;
            }
        }
        return false;
    }

    return QWidget::eventFilter(watched, event);
}

