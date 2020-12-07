#ifndef PAWN_H
#define PAWN_H
#include<box.h>

class Pawn:public Box
{
public:
    Pawn( QString Color,const int& Row,const int& Column,QWidget *parent=nullptr);
};

#endif // PAWN_H
