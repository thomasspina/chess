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


QColor toggledColour(QColor colour) {
    return colour == view::Colour::White ? view::Colour::Black : view::Colour::White;
}

void MainWindow::initBoard()
{


    int x = 0;
    QColor lastColumnTopColour = view::Colour::White;
    for (int i = 0 ; i < 8; i++) { // loop fills in board column by column

        int y = 0;
        QBrush brush = toggledColour(lastColumnTopColour);
        for (int j = 0; j < 8; j++) {

            view::BoardCase* boardCase = new view::BoardCase(10, 20, 75, 75);
            boardCase->setRect(x, y, 75, 75);
            brush = toggledColour(brush.color());
            boardCase->setBrush(brush);

            _gameView->addItem(boardCase);
            y += 75;
        }
        lastColumnTopColour = toggledColour(lastColumnTopColour);
        x += 75;
    }

}


