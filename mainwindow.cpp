#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  QPixmap chessBoard("/home/michael/QTProjects/masterChess/imagenes/tablero.jpg");
  int width_board = ui->label_tablero->width();
  int height_board = ui->label_tablero->height();
  ui->label_tablero->setPixmap(chessBoard.scaled(400 , 400, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
  delete ui;
}

