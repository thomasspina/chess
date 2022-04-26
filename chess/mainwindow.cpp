#include "mainwindow.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _gameView = new QGraphicsScene(this);
    ui->graphicsView->setScene(_gameView);

    initBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBoard()
{
    view::BoardCase* boardCase = new view::BoardCase(100, 100, 1, 8);
    boardCase->setRect(100, 100, 75, 75);
    boardCase->setBrush(QBrush(QColor::fromRgb(240, 217, 183)));

    _gameView->addItem(boardCase);
    //_gameView->addItem(&boardCase->getPixmap());

}


