#ifndef BISHOP_H
#define BISHOP_H
#include<piece.h>

class Bishop:public Piece
{
public:
    Bishop(QString Color, QWidget *parent=nullptr);
};

#endif // BISHOP_H
