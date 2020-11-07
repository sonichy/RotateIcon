#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Item *item = new Item(QPixmap(":/Safari.png"), "Safari", "Apple net browser.");
    QListWidgetItem *LWI = new QListWidgetItem(ui->listWidget);
    LWI->setSizeHint(QSize(300,100));
    ui->listWidget->setItemWidget(LWI, item);

    item = new Item(QPixmap(":/Chrome.png"), "Chrome", "The most popular net browser.");
    LWI = new QListWidgetItem(ui->listWidget);
    LWI->setSizeHint(QSize(300,100));
    ui->listWidget->setItemWidget(LWI, item);

    item = new Item(QPixmap(":/Firefox.png"), "Firefox", "Popular net browser.");
    LWI = new QListWidgetItem(ui->listWidget);
    LWI->setSizeHint(QSize(300,100));
    ui->listWidget->setItemWidget(LWI, item);
}

MainWindow::~MainWindow()
{
    delete ui;
}