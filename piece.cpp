#include "piece.h"
#include <iostream>

Piece::Piece(QWidget * parent):QWidget(parent)
{

}
std::string Piece::getColor()
{
  return this->color.toStdString();
}


