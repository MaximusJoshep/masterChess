#ifndef QUEEN_H
#define QUEEN_H
#include<piece.h>

class Queen:public Piece
{
public:
    Queen(int Row,int Column,QString Color,QWidget *parent=nullptr);
    std::string getPiece() override;
};

#endif // QUEEN_H
