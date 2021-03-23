#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->edt->setAcceptDrops(false);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->setDropAction(Qt::CopyAction);
    event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const auto mimeData = event->mimeData();
    for (const auto &format : mimeData->formats()) {
        ui->edt->appendPlainText(format);
        ui->edt->appendPlainText(QString::fromLocal8Bit(mimeData->data(format)));
        ui->edt->appendPlainText("*****");
    }
    ui->edt->appendPlainText(QString("=").repeated(50));
}
