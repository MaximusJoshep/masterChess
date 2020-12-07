#ifndef HORSE_H
#define HORSE_H
#include<box.h>

class Horse:public Box
{
public:
    Horse(QString Color,const int& Row,const int& Column,QWidget *parent=nullptr);
};

#endif // HORSE_H
