#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMimeData>
#include <QDebug>
#include <QList>
#include <QUrl>
#include <QString>
#include <QFile>
#include <QtCore5Compat/QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(!event->mimeData()->hasUrls()) {
        event->ignore();
        return;
    }

    qDebug() << "event url is : " << event->mimeData()->urls()[0];
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const auto mime_data = event->mimeData();
    if (!mime_data->hasUrls()) {
        event->ignore();
        return;
    }

    auto url_list = mime_data->urls();
    auto file_name = url_list[0].toLocalFile();

    if (file_name.isEmpty()) {
        event->ignore();
        return;
    }

    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextStream in(&file);
    ui->textEdit->append(in.readAll());

}

