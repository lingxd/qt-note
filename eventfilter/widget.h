#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "myedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
    MyEdit *my_edit_;


private:
    Q_DISABLE_COPY(Widget);
};
#endif // WIDGET_H
