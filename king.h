#ifndef KING_H
#define KING_H
#include<piece.h>

class King:public Piece
{
public:
    King(QString Color,QWidget *parent=nullptr);
    std::string getPiece() override;
};

#endif // KING_H
