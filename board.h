#ifndef BOARD_H
#define BOARD_H
#include <box.h>
#include <QWidget>
#include <vector>
#include <iostream>
#include <piece.h>

#include <string>

namespace Ui {
  class Board;
}

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    void draw_boxes();
    void draw_pieces();
    void bloquearCeldas();
    void showPosibilities(std::string pieza , int turno , int jugada);
    void markBoxPosibility(int row , int col);
    void selectBox(Box * box)
    {
      if(box != this->boxSelected && box->piece != nullptr)
      {
          this->boxSelected = box;
          std::cout<<"Seleccionado: "<<boxSelected->piece<<std::endl;
          std::string pieza = box->piece->getPiece();
          showPosibilities(pieza , 1 , 1);
      }
    }
    void moveBox(Box * otherBox)
    {
      //Si el box seleccionado no es el mismo y tampoco esta libre
      if(otherBox != this->boxSelected && otherBox->libre)
      {
        std::cout<<"Pieza movida: "<<otherBox->piece<<std::endl;

        //Actualizamos los punteros de las piezas
        otherBox->piece = boxSelected->piece;
        this->boxSelected->piece = nullptr;

        //Mostramo los iconos de las piezas
        otherBox->setIcon(QIcon(otherBox->piece->imagen));
        this->boxSelected->setIcon(QIcon());

        //Modificamos el tamaño de los iconos
        otherBox->setIconSize(QSize(50,50));

        this->boxSelected = nullptr;

        //Recargamos las celdas a su estado original
        bloquearCeldas();
      }
      else
      {
        std::cout<<"Se deja de seleccionar la pieza actual"<<std::endl;
        //Bloqueamos todas las celdas
        bloquearCeldas();
        this->boxSelected = nullptr;
      }
    }
    Box * getBoxSelected()
    {
      return this->boxSelected;
    }

private:
    Ui::Board *ui;
    Box * boxes[8][8];

    Box * boxSelected = nullptr;

};


#endif // BOARD_H
