#ifndef QUEEN_H
#define QUEEN_H
#include <box.h>

class Queen:public Box
{
public:
    Queen(QString Color,const int& Row,const int& Column,QWidget *parent=nullptr);
};

#endif // QUEEN_H
