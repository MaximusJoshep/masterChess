#include "horse.h"
#include <iostream>

Horse::Horse(int Row,int Column,QString Color,QWidget *parent):Piece(Row,Column,parent)
{
   this->color=Color;
    if(Color.compare("white")==0)
    {
        this->imagen = QPixmap("://imgs/horse1.png");
    }
    else
    {
        this->imagen = QPixmap("://imgs/horse.png");
    }
}

std::string Horse::getPiece()
{
  return "horse";
}
