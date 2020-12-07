#include "box.h"
#include <QDebug>
Box::Box(const int& Row,const int& Column,QWidget *parent ):QPushButton(parent)
{
     int SHIFT = 90;
    this->row=Row;
    this->column=column;
    this->move(Row+Column*SHIFT,Column+Row*SHIFT);
    if((Column+Row)%2==0)
    {
        this->setStyleSheet("background-color: #7E3B3A;" "width: 80px;" "height:80px");

    }
    else
    {
        this->setStyleSheet("background-color: #FFFFFF;" "width: 80px;" "height:80px");
    }
    this->show();


}
Box::~Box()
{
    delete this;
}
void Box::setColor(QColor color)
{


}
