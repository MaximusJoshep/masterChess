#include "bishop.h"
#include <iostream>
#include <string>
Bishop::Bishop(int Row,int Column,QString Color,QWidget *parent):Piece(Row,Column,parent)
{

     this->color=Color;
      if(Color.compare("white")==0)
      {
          this->imagen = QPixmap("://imgs/bishop1.png");
      }
      else
      {
          this->imagen = QPixmap("://imgs/bishop.png");
      }
}
std::string Bishop::getPiece()
{
  return "bishop";
}

