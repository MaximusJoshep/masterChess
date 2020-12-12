#include "queen.h"
#include <iostream>
Queen::Queen(QString Color,QWidget *parent):Piece(parent)
{
     this->color=Color;
      if(Color.compare("white")==0)
      {
          this->imagen = QPixmap("://imgs/queen1.png");
      }
      else
      {
          this->imagen = QPixmap("://imgs/queen.png");
      }
}

std::string Queen::getPiece()
{
  return "queen";
}
