#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>
#include <QTimerEvent>
#include <QDebug>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::ClickFocus);

//    id1 = startTimer(1000);
//    id2 = startTimer(1500);
//    id3 = startTimer(2000);
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::slotUpdateLED);
    timer->start(1000);

}

Widget::~Widget()
{
    delete ui;
//    killTimer(id1);
//    killTimer(id2);
//    killTimer(id3);
}

void Widget::slotUpdateLED()
{
    auto current_time = QTime::currentTime();
    auto current_time_text = current_time.toString("hh:mm:ss");
    qDebug() << "current time is : " << current_time_text;
    if (current_time.second() % 2 == 0) {
        current_time_text[5] = ' ';
        current_time_text[2] = ' ';
    }
    ui->lcdNumber->setDigitCount(current_time_text.length());
    ui->lcdNumber->display(current_time_text);
}

void Widget::keyPressEvent(QKeyEvent *event) {
    if (event->modifiers() == Qt::ControlModifier) {
        if (event->key() == Qt::Key_M && windowState() != Qt::WindowFullScreen) {
            setWindowState(Qt::WindowFullScreen);
            return;
        }
        return;
    }

    if (event->key() == Qt::Key_Escape && windowState() == Qt::WindowFullScreen) {
        setWindowState(Qt::WindowNoState);
        return;
    }

    bool b_upflag = false;
    bool b_downflag = false;
    bool b_leftflag = false;
    bool b_rightflag = false;

    if (event->key() == Qt::Key_Up) {
        if (event->isAutoRepeat()) {
            auto curpos = ui->pushButton->pos();
            curpos.setY(curpos.y() - 5);
            ui->pushButton->move(curpos);
        } else {
            b_upflag = true;
        }
    }

    if (event->key() == Qt::Key_Down) {
        if (event->isAutoRepeat()) {
            auto curpos = ui->pushButton->pos();
            curpos.setY(curpos.y() + 5);
            ui->pushButton->move(curpos);
        } else {
            b_downflag = true;
        }
    }

    if (event->key() == Qt::Key_Left) {
        if (event->isAutoRepeat()) {
            auto curpos = ui->pushButton->pos();
            curpos.setX(curpos.x() - 5);
            ui->pushButton->move(curpos);
        } else {
            b_leftflag = true;
        }
    }

    if (event->key() == Qt::Key_Right) {
        if (event->isAutoRepeat()) {
            auto curpos = ui->pushButton->pos();
            curpos.setX(curpos.x() + 5);
            ui->pushButton->move(curpos);
        } else {
            b_rightflag = true;
        }
    }

    auto curpos = ui->pushButton->pos();
    if (b_upflag) {
        curpos.setY(curpos.y() - 5);
    }

    if (b_downflag) {
        curpos.setY(curpos.y() + 5);
    }

    if (b_leftflag) {
        curpos.setX(curpos.x() - 5);
    }

    if (b_rightflag) {
        curpos.setX(curpos.x() + 5);
    }

    ui->pushButton->move(curpos);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1) {
        qDebug() << "id1 timer triggered";
    }

    if (event->timerId() == id2) {
        qDebug() << "id2 timer triggered";
    }

    if (event->timerId() == id3) {
        qDebug() << "id3 timer triggered";
    }
}
