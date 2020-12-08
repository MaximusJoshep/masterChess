#ifndef TOWER_H
#define TOWER_H
#include<piece.h>

class Tower:public Piece
{
public:
    Tower(QString Color,QWidget *parent=nullptr);
};

#endif // TOWER_H
