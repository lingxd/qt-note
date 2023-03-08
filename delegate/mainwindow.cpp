#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>

#include "spinboxdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto model = new QStandardItemModel(7, 4, this);
    for (int row = 0; row < 7; row++) {
        for (int columu = 0; columu < 4; columu++) {
            auto item = new QStandardItem(QString("%1").arg(row * 4 + columu));
            model->setItem(row, columu, item);
        }
    }

    auto table_view = new QTableView(this);
    table_view->setModel(model);
    setCentralWidget(table_view);
    this->resize(800, 800);

    auto model2 = new QStandardItemModel(7, 4, this);
    for (int row = 0; row < 7; row++) {
        for (int columu = 0; columu < 4; columu++) {
            auto item = new QStandardItem(QString("%1").arg(row * 4 + columu));
            model2->setItem(row, columu, item);
        }
    }

    auto delegate = new SpinBoxDelegate(this);

    table_view_ = new QTableView();
    table_view_->setModel(model2);
    table_view_->setItemDelegate(delegate);
    table_view_->show();
    table_view_->resize(800, 800);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete table_view_;
}

