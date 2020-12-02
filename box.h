#ifndef BOX_H
#define BOX_H

#include<QPainter>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPushButton>

class Box:public QPushButton
{
public:
    Box(QWidget *parent = nullptr);
    ~Box();
    void setColor(QColor color);
    int row;
    int column;
private:

};



#endif // BOX_H
