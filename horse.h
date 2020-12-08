#ifndef HORSE_H
#define HORSE_H
#include<piece.h>

class Horse:public Piece
{
public:
    Horse(QString Color,QWidget *parent=nullptr);
};

#endif // HORSE_H
