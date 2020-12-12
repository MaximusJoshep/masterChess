#ifndef PAWN_H
#define PAWN_H
#include<piece.h>

class Pawn:public Piece
{
public:
    Pawn(QString Color,QWidget *parent=nullptr);
    std::string getPiece() override;
};

#endif // PAWN_H
