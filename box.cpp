#include "box.h"
#include "board.h"
#include <QDebug>
Box::Box(const int& Row,const int& Column,QWidget *parent ):QPushButton(parent)
{
    //Añadimos el listener del click a los botones
    connect(this , SIGNAL (clicked()), this, SLOT (boxClickHandler()));
    piece = nullptr;
    int SHIFT = 90;
    this->row=Row;
    this->column=Column;

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

void Box::boxClickHandler()
{
  Board * parent = static_cast<Board*>(this->parent());
  if(parent->getBoxSelected() == nullptr)
  {
      //seleccionamos la pieza
      parent->selectBox(this);
  }
  else
  {
      //Movemos la pieza
      parent->moveBox(this);

  }
}
void Box::markBox()
{
  this->show();
}
