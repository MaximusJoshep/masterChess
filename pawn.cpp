#include "pawn.h"

#include <iostream>

Pawn::Pawn(int Row,int Column,QString Color,QWidget *parent):Piece(Row,Column,parent)
{
    this->color=Color;
    if(Color.compare("white")==0)
    {
        this->imagen = QPixmap("://imgs/pawn1.png");
    }
    else
    {
        this->imagen = QPixmap("://imgs/pawn.png");
    }

}
std::string Pawn::getPiece()
{
  return "pawn";
}
