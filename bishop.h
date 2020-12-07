#ifndef BISHOP_H
#define BISHOP_H
#include <box.h>


class Bishop:public Box
{
public:
    Bishop(QString Color,const int& Row,const int& Column,QWidget *parent=nullptr);
};

#endif // BISHOP_H
