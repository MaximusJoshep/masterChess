#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    boxes=std::vector<Box *>(64);

    ui->setupUi(this);
     draw();


}

Board::~Board()
{
    delete ui;
}
void Board::draw()
{

     int SHIFT = 80;
     for(int i = 0; i < 8; i++) {
         for(int j = 0; j < 8; j++)
         {

             Box *box = new Box(this);
             box->row = i;
             box->column = j;
             box->move(i* SHIFT,j* SHIFT);
             if((i+j)%2==0)
                box->setStyleSheet("background-color: #7E3B3A;" "width: 80px;" "height:80px");
             else
             box->setStyleSheet("background-color: #FFFFFF;" "width: 80px;" "height:80px");
             box->show();
             boxes.push_back(box);

         }
     }

}
Box& Board::operator () (const unsigned& i,const unsigned& j)
    {
        return *boxes[(i*8)+j];
    }


