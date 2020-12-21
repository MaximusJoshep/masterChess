#ifndef BOX_H
#define BOX_H

#include<QPainter>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPushButton>
#include <iostream>
#include "piece.h"

class Box:public QPushButton
{
  Q_OBJECT
public:
    Box(const int& Row,const int& Column,QWidget *parent = nullptr);
    ~Box();

    bool libre{false};

    Piece * piece;
    int row;
    int column;

    void reloadColor();
    void markBox();
    void markCastlingBox();
    void markDangerBox();

public Q_SLOTS:
    void boxClickHandler();
    friend bool operator== (const Box& a, const Box& b)
        {
              if(a.row==b.row&&a.column==b.column)
              {
                  return true;
              }


            return false;
        }
    friend bool operator!= (const Box& a, const Box& b)
        {


            return !(a==b);
        }

private:
};

#endif // BOX_H
