#include "horse.h"

Horse::Horse(QString Color,QWidget *parent):Piece(parent)
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
