#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QItemSelection>
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto model = new QStandardItemModel(7, 4, this);
    for (int row = 0; row < 7; row++) {
        for (int column = 0; column < 4; column++) {
            auto item = new QStandardItem(QString("%1").arg(row * 4 + column));
            model->setItem(row, column, item);
        }
    }

    table_view_ = new QTableView(this);
    table_view_->setModel(model);
    setCentralWidget(table_view_);
    this->resize(800, 800);

    auto selection_model = table_view_->selectionModel();

    QModelIndex top_left;
    QModelIndex bottom_right;
    top_left = model->index(1, 1, QModelIndex());
    bottom_right = model->index(5, 2, QModelIndex());

    QItemSelection selection(top_left, bottom_right);
    selection_model->select(selection, QItemSelectionModel::Select);

    table_view2_ = new QTableView();
    table_view2_->setWindowTitle("tableView2");
    table_view2_->resize(800, 800);
    table_view2_->setModel(model);
    table_view2_->setSelectionModel(selection_model);
    table_view2_->show();

    ui->maintoolBar->addAction(tr("当前项目"), this, &MainWindow::getCurrentItem);
    ui->maintoolBar->addAction(tr("切换选中"), this, &MainWindow::toggleSelection);

    // 选择模型的选择条目后改变
    connect(selection_model, &QItemSelectionModel::selectionChanged, this, &MainWindow::updateSelection);
    //选择模型更改
    connect(selection_model, &QItemSelectionModel::currentChanged, this, &MainWindow::changedCurrent);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete table_view2_;
}

void MainWindow::getCurrentItem()
{
    auto current_item = table_view_->selectionModel()->currentIndex().data().toString();
    qDebug() << "current item : " << current_item;
}

void MainWindow::toggleSelection()
{
    auto top_left = table_view_->model()->index(0, 0, QModelIndex());
    auto max_row = table_view_->model()->rowCount(QModelIndex());
    auto max_column = table_view_->model()->columnCount(QModelIndex());

    // 根据行列获取右下角的item 索引
    auto bottom_right = table_view_->model()->index(max_row - 1, max_column - 1, QModelIndex());

    QItemSelection cur_selection(top_left, bottom_right);
    table_view_->selectionModel()->select(cur_selection, QItemSelectionModel::Toggle);

}

void MainWindow::updateSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    foreach (auto index, selected.indexes()) {
        auto text = QString("(%1, %2)").arg(index.row()).arg(index.column());
        table_view_->model()->setData(index, text);
    }

    foreach (auto index, deselected.indexes()) {
        table_view_->model()->setData(index, " ");
    }

}

void MainWindow::changedCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug() << tr("move(%1, %2) to (%3, %4)").arg(previous.row()).arg(previous.column())
                .arg(current.row()).arg(current.column());
}

