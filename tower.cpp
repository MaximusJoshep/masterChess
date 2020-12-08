#include "tower.h"

Tower::Tower(QString Color,QWidget *parent):Piece(parent)
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
