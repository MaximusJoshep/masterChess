#include "pawn.h"

Pawn::Pawn(QString Color,QWidget *parent):Piece(parent)
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
