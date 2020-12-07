#ifndef BOX_H
#define BOX_H

#include<QPainter>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPushButton>

class Box:public QPushButton
{
public:
    Box( const int& Row,const int& Column,QWidget *parent = nullptr);
    ~Box();
    void setColor(QColor color);
    bool hasPiece{false};
    int row;
    int column;
    QString color{"white"};
private:

};



#endif // BOX_H
