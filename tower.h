#ifndef TOWER_H
#define TOWER_H
#include<box.h>

class Tower:public Box
{
public:
    Tower(QString Color,const int& Row,const int& Column,QWidget *parent=nullptr);
};

#endif // TOWER_H
