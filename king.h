#ifndef KING_H
#define KING_H
#include<box.h>

class King:public Box
{
public:
    King(QString Color,const int& Row,const int& Column,QWidget *parent=nullptr);
};

#endif // KING_H
