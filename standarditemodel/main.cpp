#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QPixmap>
#include <QTreeView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QStandardItemModel model;
    auto* parent_item = model.invisibleRootItem();
    auto* item0 = new QStandardItem();
    item0->setText("item0");
    QPixmap pixmap0(50, 50);
    pixmap0.fill(Qt::red);
    item0->setIcon(pixmap0);
    item0->setToolTip("indexA");
    parent_item->appendRow(item0);

    parent_item = item0;

    auto* item1 = new QStandardItem();
    item1->setText("item1");
    QPixmap pixmap1(50, 50);
    pixmap1.fill(Qt::blue);
    item1->setIcon(pixmap1);
    item1->setToolTip("indexB");
    parent_item->appendRow(item1);

//    auto* item2 = new QStandardItem();
//    item2->setText("item2");
//    QPixmap pixmap2(50, 50);
//    pixmap2.fill(Qt::green);
//    item2->setIcon(pixmap2);
//    item2->setToolTip("indexC");
//    parent_item->appendRow(item2);
    auto* item2 = new QStandardItem();
    item2->setData("item2", Qt::EditRole);
    item2->setData("indexC", Qt::ToolTipRole);
    QPixmap pixmap2(50, 50);
    pixmap2.fill(Qt::green);
    item2->setData(QIcon(pixmap2), Qt::DecorationRole);
    parent_item->appendRow(item2);

    // get root (row 0, col 0) model index
    auto indexA = model.index(0, 0, QModelIndex());
    qDebug() << "model indexA row count is " << model.rowCount(indexA);

    // get index (row 0, col 0)
    auto indexB = model.index(0, 0, indexA);
    qDebug() << "model indexB (row 0, col 0) text is " << model.data(indexB, Qt::EditRole).toString();
    qDebug() << "model indexB (row 0, col 0) icon is " << model.data(indexB, Qt::DecorationRole);
    qDebug() << "model indexB (row 0, col 0) top is " << model.data(indexB, Qt::ToolTipRole).toString();


    QTreeView tree_view;
    tree_view.setModel(&model);
    tree_view.show();

    return a.exec();
}
