#include "board.h"
#include "ui_board.h"
#include "horse.h"
#include "pawn.h"
#include "tower.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{


    ui->setupUi(this);

     draw_boxes();



}

Board::~Board()
{
    delete ui;
}
void Board::draw_boxes()

{
    this->boxes[0][0]=new Tower("white",0,0,this);
    this->boxes[0][7]=new Tower("white",0,7,this);

    this->boxes[7][0]=new Tower("black",7,0,this);
    this->boxes[7][7]=new Tower("black",7,7,this);


    this->boxes[0][1]=new Horse("white",0,1,this);
    this->boxes[0][6]=new Horse("white",0,6,this);

    this->boxes[7][1]=new Horse("black",7,1,this);
    this->boxes[7][6]=new Horse("black",7,6,this);




    this->boxes[0][2]=new Bishop("white",0,2,this);
    this->boxes[0][5]=new Bishop("white",0,5,this);

    this->boxes[7][2]=new Bishop("black",7,2,this);
    this->boxes[7][5]=new Bishop("black",7,5,this);

    this->boxes[0][3]=new Queen("white",0,3,this);
    this->boxes[7][3]=new Queen("black",7,3,this);

    this->boxes[0][4]=new King("white",0,4,this);
    this->boxes[7][4]=new King("black",7,4,this);



     for(int i = 1; i < 7; i++) {
         for(int j = 0; j < 8; j++)
         {

            if(i==1)
            {
                this->boxes[i][j] = new Pawn("white",i,j,this);

            }
            else if(i==6)
            {
                this->boxes[i][j] = new Pawn("black",i,j,this);


            }else{
             this->boxes[i][j] = new Box(i,j,this);
            }



         }

     }


}
void Board::draw_pieces()
{

}



