#ifndef BOARD_H
#define BOARD_H
#include <box.h>
#include <QWidget>
#include <vector>
#include <iostream>

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
     void draw();




private:
    Ui::Board *ui;
    std::vector<Box *> boxes;

};

#endif // BOARD_H
