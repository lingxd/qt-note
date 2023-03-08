#include "mainwindow.h"

#include <QApplication>
#include <QStringList>
#include <QTableView>
#include <QListView>

#include "stringlistmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QStringList list;
    list << "a" << "b" << "c";
    StringListModel model(list);

    model.insertRows(3, 2);
    model.removeRows(1, 1);

    QTableView table_view;
    table_view.setModel(&model);
    table_view.show();

    QListView list_view;
    list_view.setModel(&model);
    list_view.show();

    return a.exec();
}
