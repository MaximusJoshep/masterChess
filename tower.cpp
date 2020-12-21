#include "tower.h"
#include <iostream>
Tower::Tower(int Row,int Column,QString Color,QWidget *parent):Piece(Row,Column,parent)
{
     this->color=Color;
      if(Color.compare("white")==0)
      {
          this->imagen = QPixmap("://imgs/rook1.png");
      }
      else
      {
          this->imagen = QPixmap("://imgs/rook.png");
      }
}

std::string Tower::getPiece()
{
  return "tower";
}
