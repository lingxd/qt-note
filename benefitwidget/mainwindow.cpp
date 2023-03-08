#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QListWidget>
#include <QListWidgetItem>
#include <QPixmap>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto list_widget = new QListWidget(this);

    auto list_widtet_item = new QListWidgetItem(list_widget);
    list_widtet_item->setText("list item");
    QPixmap pixmap(50, 50);
    pixmap.fill(Qt::blue);
    list_widtet_item->setIcon(pixmap);
    list_widtet_item->setToolTip("this is list item");
    list_widget->insertItem(0, list_widtet_item);

    auto list_widtet_item2 = new QListWidgetItem(list_widget);
    list_widtet_item2->setText("list item2");
    QPixmap pixmap2(50, 50);
    pixmap2.fill(Qt::red);
    list_widtet_item2->setIcon(pixmap2);
    list_widtet_item2->setToolTip("this is list item2");
    list_widget->insertItem(1, list_widtet_item2);

    list_widget->setSortingEnabled(true);
    list_widget->sortItems(Qt::DescendingOrder);

    //设置list为单选模式
    list_widget->setSelectionMode(QAbstractItemView::SingleSelection);
    //启用拖动
    list_widget->setDragEnabled(true);
    //设置接受拖放
    list_widget->viewport()->setAcceptDrops(true);
    //设置显示将要放置的位置
    list_widget->setDropIndicatorShown(true);
    //设置拖放模式为移动项目，如果不设置，则为复制项目
    list_widget->setDragDropMode(QAbstractItemView::DragOnly);

    list_widget->show();
    this->setCentralWidget(list_widget);

    tree_widget_ = new QTreeWidget();
    tree_widget_->setColumnCount(2);
    QStringList headers;
    headers << "name" << "year";
    tree_widget_->setHeaderLabels(headers);

    auto grade1 = new QTreeWidgetItem(tree_widget_);
    grade1->setText(0, "Grade1");

    auto student1 = new QTreeWidgetItem(grade1);
    student1->setText(0, "Tom");
    student1->setText(1, "1999");

    auto student2 = new QTreeWidgetItem(grade1, student1);
    student2->setText(0, "Jack");
    student2->setText(1, "1992");

    auto grade2 = new QTreeWidgetItem(tree_widget_, grade1);
    grade2->setText(0, "Grade2");

    auto student3 = new QTreeWidgetItem(grade1, student2);
    student3->setText(0, "Mali");
    student3->setText(1, "1992");

    auto parent_student3 = student3->parent();
    auto index_student3 = parent_student3->indexOfChild(student3);
    delete parent_student3->takeChild(index_student3);

    auto parent_grade2 = grade2->parent();
    assert(parent_grade2 == nullptr);
    auto index_grade2 = tree_widget_->indexOfTopLevelItem(grade2);
    delete tree_widget_->takeTopLevelItem(index_grade2);

    tree_widget_->show();

    table_widget_ = new QTableWidget(3, 2);
    auto table_widget_item = new QTableWidgetItem("qt");
    table_widget_->setItem(0, 0, table_widget_item);

    auto header_v = new QTableWidgetItem("year");
    table_widget_->setVerticalHeaderItem(0, header_v);

    auto header_h = new QTableWidgetItem("id");
    table_widget_->setHorizontalHeaderItem(0, header_h);

    table_widget_->show();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree_widget_;
    delete table_widget_;
}

