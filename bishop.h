#ifndef BISHOP_H
#define BISHOP_H
#include<piece.h>
#include <string>
class Bishop:public Piece
{
public:
    Bishop(QString Color, QWidget *parent=nullptr);
    std::string getPiece() override;
};

#endif // BISHOP_H
