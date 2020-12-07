#include "tower.h"

Tower::Tower(QString Color,const int& Row,const int& Column,QWidget *parent):Box(Row,Column,parent)
{
    this->hasPiece=true;
     this->color=Color;
      if(Color.compare("white")==0)
      {
          this->setIcon(QIcon("://imgs/rook1.png"));
      }
      else
      {
          this->setIcon(QIcon("://imgs/rook.png"));
      }
      this->setIconSize(QSize(50,50));
}
