#include "piece.h"
#include <iostream>

Piece::Piece(int Row,int Column,QWidget * parent):QWidget(parent)
{
 this->row=Row;
 this->column=Column;

}
std::string Piece::getColor()
{
  return this->color.toStdString();
}


