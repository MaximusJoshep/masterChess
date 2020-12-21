#include "king.h"
#include <iostream>
King::King(int Row,int Column,QString Color,QWidget *parent):Piece(Row,Column,parent)
{
     this->color=Color;
      if(Color.compare("white")==0)
      {
          this->imagen = QPixmap("://imgs/king1.png");
      }
      else
      {
          this->imagen = QPixmap("://imgs/king.png");
      }

}

std::string King::getPiece()
{
  return "king";
}

