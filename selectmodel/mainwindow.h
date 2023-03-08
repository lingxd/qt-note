#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTableView *table_view_;
    QTableView *table_view2_;

private slots:
    void getCurrentItem();
    void toggleSelection();

    void updateSelection(const QItemSelection &selected, const QItemSelection &deselected);
    void changedCurrent(const QModelIndex &current, const QModelIndex &previous);

};
#endif // MAINWINDOW_H
