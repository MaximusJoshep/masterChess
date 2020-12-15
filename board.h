#ifndef BOARD_H
#define BOARD_H
#include <box.h>
#include <QWidget>
#include <vector>
#include <iostream>
#include <piece.h>

#include <string>

namespace Ui {
  class Board;
}

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    void draw_boxes();
    void draw_pieces();
    void bloquearCeldas();
    void showPosibilities(std::string pieza  , int jugada);
    void markBoxPosibility(int row , int col);
    void selectBox(Box * box);
    void moveBox(Box * otherBox);
    Box * getBoxSelected();
    void changeTurn();
    void markDanger(int row , int col);


private:
    Ui::Board *ui;
    Box * boxes[8][8];
    int turn=0;
    Box * boxSelected = nullptr;

};


#endif // BOARD_H
