#include "board.h"
#include "ui_board.h"
#include "horse.h"
#include "pawn.h"
#include "tower.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include <QtWidgets>

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);

    draw_boxes();
    draw_pieces();
}

Board::~Board()
{
    delete ui;
}
void Board::bloquearCeldas()
{
  for(int i=0 ; i<8 ; i++)
      for(int j=0 ; j<8 ; j++)
        {
          this->boxes[i][j]->libre = false;
          this->boxes[i][j]->reloadColor();
        }
}
void Board::draw_pieces()
{
  for(int i=0 ; i<8 ; i++)
  {
      for(int j=0 ; j<8 ; j++)
      {
        if(this->boxes[i][j]->piece != nullptr)
          {
            this->boxes[i][j]->setIcon(boxes[i][j]->piece->imagen);
            this->boxes[i][j]->setIconSize(QSize(50,50));
          }
      }
  }
}
void Board::draw_boxes()
{
    this->boxes[0][0] = new Box(0,0,this);
    boxes[0][0]->piece = new Tower("white",this);
    this->boxes[0][7] = new Box(0,7,this);
    boxes[0][7]->piece = new Tower("white",this);

    this->boxes[7][0]=new Box(7,0,this);
    this->boxes[7][0]->piece = new Tower("black",this);
    this->boxes[7][7]=new Box(7,7,this);
    this->boxes[7][7]->piece = new Tower("black",this);

    this->boxes[0][1]=new Box(0,1,this);
    this->boxes[0][1]->piece = new Horse("white",this);
    this->boxes[0][6]=new Box(0,6,this);
    this->boxes[0][6]->piece = new Horse("white",this);

    this->boxes[7][1]=new Box(7,1,this);
    this->boxes[7][1]->piece=new Horse("black",this);
    this->boxes[7][6]=new Box(7,6,this);
    this->boxes[7][6]->piece = new Horse("black",this);

    this->boxes[0][2]=new Box(0,2,this);
    this->boxes[0][2]->piece = new Bishop("white",this);
    this->boxes[0][5]=new Box(0,5,this);
    this->boxes[0][5]->piece = new Bishop("white",this);

    this->boxes[7][2]=new Box(7,2,this);
    this->boxes[7][2]->piece = new Bishop("black",this);
    this->boxes[7][5]=new Box(7,5,this);
    this->boxes[7][5]->piece = new Bishop("black",this);

    this->boxes[0][3]=new Box(0,3,this);
    this->boxes[0][3]->piece = new Queen("white",this);
    this->boxes[7][3]=new Box(7,3,this);
    this->boxes[7][3]->piece = new Queen("black",this);

    this->boxes[0][4]=new Box(0,4,this);
    this->boxes[0][4]->piece = new King("white",this);
    this->boxes[7][4]=new Box(7,4,this);
    this->boxes[7][4]->piece = new King("black",this);

     for(int i = 1; i < 7; i++) {
         for(int j = 0; j < 8; j++)
         {
            if(i==1)
            {
                this->boxes[i][j] = new Box(i,j,this);
                this->boxes[i][j]->piece = new Pawn("white",this);
            }
            else if(i==6)
            {
                this->boxes[i][j] = new Box(i,j,this);
                this->boxes[i][j]->piece = new Pawn("black",this);
            }
            else
            {
                this->boxes[i][j] = new Box(i,j,this);
            }
        }
     }
}

void Board::markBoxPosibility(int row , int col)
{
  //Mientras no se salga del tablero
  if(row<0 || 7<row || col<0 || 7<col)
    return;
  this->boxes[row][col]->libre = true;
  this->boxes[row][col]->markBox();
}
void Board::showPosibilities(std::string pieza , int turno , int jugada)
{
  //Dependiendo de la ficha y el turno, se mostraran las posiciones de cada elemento
  if(turno == 0)  //Turno del primer jugador
  {
      //Si se trata de un peon
      if(pieza.compare("pawn")==0)
      {
        std::cout<<"Mostrar opciones de la pieza pawn"<<std::endl;
        markBoxPosibility(this->boxSelected->row-1 , boxSelected->column);
        if(jugada == 1)  //En el primer turno, el peon salta 2 casillas
          //Habilitamos las 2 posiciones que le pertenecen
          markBoxPosibility(boxSelected->row-2 , boxSelected->column);
      }
  }
  else      //Turno del segundo jugador
  {
      //Si se trata de un peon
      if(pieza.compare("pawn")==0)
      {
        std::cout<<"Mostrar opciones de la pieza pawn"<<std::endl;
        markBoxPosibility(this->boxSelected->row+1 , boxSelected->column);
        if(jugada == 1)  //En el primer turno, el peon salta 2 casillas
          //Habilitamos las 2 posiciones que le pertenecen
          markBoxPosibility(boxSelected->row+2 , boxSelected->column);
      }

  }
}


