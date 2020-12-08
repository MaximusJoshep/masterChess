#ifndef QUEEN_H
#define QUEEN_H
#include<piece.h>

class Queen:public Piece
{
public:
    Queen(QString Color,QWidget *parent=nullptr);
};

#endif // QUEEN_H
