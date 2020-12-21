#ifndef PAWN_H
#define PAWN_H
#include<piece.h>

class Pawn:public Piece
{
public:
    Pawn(int Row,int Column, QString Color,QWidget *parent=nullptr);
    std::string getPiece() override;
    bool vulnerableCapturaPaso{false};
};

#endif // PAWN_H
