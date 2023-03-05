#ifndef MYEDIT_H
#define MYEDIT_H

#include <QLineEdit>

class MyEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyEdit(QWidget *parent = nullptr);
    ~MyEdit();

protected:
    void keyPressEvent(QKeyEvent *event);
    bool event(QEvent *event);

private:
    Q_DISABLE_COPY(MyEdit);
};

#endif // MYEDIT_H
