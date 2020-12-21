#ifndef TOWER_H
#define TOWER_H
#include<piece.h>

class Tower:public Piece
{
public:
    Tower(int Row,int Column,QString Color,QWidget *parent=nullptr);
    std::string getPiece() override;
};

#endif // TOWER_H
