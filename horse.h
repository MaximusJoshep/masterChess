#ifndef HORSE_H
#define HORSE_H
#include<piece.h>

class Horse:public Piece
{
public:
    Horse(int Row,int Column,QString Color,QWidget *parent=nullptr);
    std::string getPiece() override;
};

#endif // HORSE_H
