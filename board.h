#ifndef BOARD_H
#define BOARD_H
#include <box.h>
#include <QWidget>
#include <vector>
#include <iostream>
#include <piece.h>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    Box& operator () (const unsigned& i,const unsigned& j);
    ~Board();
     void draw_boxes();
     void draw_pieces();




private:
    Ui::Board *ui;
     Box* boxes[8][8];

};

#endif // BOARD_H
