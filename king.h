#ifndef KING_H
#define KING_H
#include<piece.h>

class King:public Piece
{
public:
    King(QString Color,QWidget *parent=nullptr);
};

#endif // KING_H
