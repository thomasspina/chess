#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#define CASE_SIZE 75 // TODO adjust the size dynamically according to the screen size
#define BOARD_SIZE 8

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


QColor toggledColour(QColor colour)
{
    return colour == view::Colour::White ? view::Colour::Black : view::Colour::White;
}


void MainWindow::initBoard()
{
    int x = 0;
    QColor lastColumnTopColour = view::Colour::White; // to flip board change to black
    for (int i = 0 ; i < BOARD_SIZE; i++) { // loop fills in board column by column

        int y = 0;
        QBrush brush = toggledColour(lastColumnTopColour);
        for (int j = 0; j < BOARD_SIZE; j++) {

            view::BoardCase* boardCase = new view::BoardCase(x, y, CASE_SIZE, CASE_SIZE);
            boardCase->setRect(x, y, CASE_SIZE, CASE_SIZE);
            brush = toggledColour(brush.color());
            boardCase->setBrush(brush);

            _gameView->addItem(boardCase);
            y += CASE_SIZE;
        }
        lastColumnTopColour = toggledColour(lastColumnTopColour);
        x += CASE_SIZE;
    }
}
