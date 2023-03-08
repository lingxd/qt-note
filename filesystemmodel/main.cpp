#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    auto* splitter = new QSplitter;
    auto* model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    auto* tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    auto* list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("two views onto same system");
    splitter->resize(1000, 800);
    splitter->show();

    return a.exec();
}
