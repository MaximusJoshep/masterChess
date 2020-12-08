#include "queen.h"

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
