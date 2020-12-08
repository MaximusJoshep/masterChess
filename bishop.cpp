#include "bishop.h"

Bishop::Bishop(QString Color,QWidget *parent):Piece(parent)
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
