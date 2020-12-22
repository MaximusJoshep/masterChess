#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "piece.h"
#include <string>
#include "promoteform.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void registrarMovimiento(std::string cadena);
  void addPiezaEliminada(Piece * pieza);
  void showPiecePromoteOptions(Box * box);
private slots:
  void promoteToHorse();
  void promoteToBishop();
  void promoteToQueen();
  void promoteToTower();
private:
  Ui::MainWindow *ui;
  Box * box;
  QWidget * pantalla;
};
#endif // MAINWINDOW_H
