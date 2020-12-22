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
    boxes[0][0]->piece = new Tower(0,0,"white",this);
    this->boxes[0][7] = new Box(0,7,this);
    boxes[0][7]->piece = new Tower(0,7,"white",this);

    this->boxes[7][0]=new Box(7,0,this);
    this->boxes[7][0]->piece = new Tower(7,0,"black",this);
    this->boxes[7][7]=new Box(7,7,this);
    this->boxes[7][7]->piece = new Tower(7,7,"black",this);

    this->boxes[0][1]=new Box(0,1,this);
    this->boxes[0][1]->piece = new Horse(0,1,"white",this);
    this->boxes[0][6]=new Box(0,6,this);
    this->boxes[0][6]->piece = new Horse(0,6,"white",this);

    this->boxes[7][1]=new Box(7,1,this);
    this->boxes[7][1]->piece=new Horse(7,1,"black",this);
    this->boxes[7][6]=new Box(7,6,this);
    this->boxes[7][6]->piece = new Horse(7,6,"black",this);

    this->boxes[0][2]=new Box(0,2,this);
    this->boxes[0][2]->piece = new Bishop(0,2,"white",this);
    this->boxes[0][5]=new Box(0,5,this);
    this->boxes[0][5]->piece = new Bishop(0,5,"white",this);

    this->boxes[7][2]=new Box(7,2,this);
    this->boxes[7][2]->piece = new Bishop(7,2,"black",this);
    this->boxes[7][5]=new Box(7,5,this);
    this->boxes[7][5]->piece = new Bishop(7,5,"black",this);

    this->boxes[0][3]=new Box(0,3,this);
    this->boxes[0][3]->piece = new Queen(0,3,"white",this);
    this->boxes[7][3]=new Box(7,3,this);
    this->boxes[7][3]->piece = new Queen(7,3,"black",this);

    this->boxes[0][4]=new Box(0,4,this);
    this->boxes[0][4]->piece = new King(0,4,"white",this);
    this->boxes[7][4]=new Box(7,4,this);
    this->boxes[7][4]->piece = new King(7,4,"black",this);

     for(int i = 1; i < 7; i++) {
         for(int j = 0; j < 8; j++)
         {
            if(i==1)
            {
                this->boxes[i][j] = new Box(i,j,this);
                this->boxes[i][j]->piece = new Pawn(i,j,"white",this);
            }
            else if(i==6)
            {
                this->boxes[i][j] = new Box(i,j,this);
                this->boxes[i][j]->piece = new Pawn(i,j,"black",this);
            }
            else
            {
                this->boxes[i][j] = new Box(i,j,this);
            }
        }
     }
     //Llenamos el vector de las fichas blancas
     for(int i=0;i<2;i++)
     {
         for(int j=0;j<8;j++)
         {
             if(j!=4){
                   whitePieces.push_back(this->boxes[i][j]->piece);
              }
         }
     }
     //Llenamos el vector de las fichas negras
     for(int i=6;i<8;i++)
     {
         for(int j=0;j<8;j++)
         {
             if(j!=4){
                   blackPieces.push_back(this->boxes[i][j]->piece);
              }
         }
     }

}

void Board::markCastling(int row, int col)
{

    //Comprobamos que de ambas piezas sea su primera jugada
    if(this->boxes[row][col]->piece==nullptr)
    {
        return;
    }
    if(this->boxSelected->piece->move==1 && this->boxes[row][col]->piece->move==1)
    {
        this->boxes[row][col]->markCastlingBox();
        this->boxes[row][col]->libre = true;
    }
}
void Board::getDangerPossibility(Box* box,int row , int col ,std::vector<Box*> &possibilities)
{
    if(this->boxes[row][col]->piece->color.compare(box->piece->color)==0){
       return;
    }
    possibilities.push_back(boxes[row][col]);
}
void Board::getBoxPosibility(Box* box,int row , int col,std::vector<Box*> &possibilities)
{
  //Mientras no se salga del tablero
  if(row<0 || 7<row || col<0 || 7<col){
    return;
  }
  if(boxes[row][col]->piece!=nullptr)
  {
    getDangerPossibility(box,row,col,possibilities);
  }
  else
  {
    possibilities.push_back(boxes[row][col]);
  }
}
std::vector<Box*> Board::getPosibilities(Box* box)
{
  std::vector<Box*> possibilities;
  if(box->piece->getPiece().compare("pawn")==0)
  {
    if(box->piece->getColor().compare("white")==0)
    {
        //Movimiento
        if(-1<box->row+1 && box->row+1<8 && boxes[box->row+1][box->column]->piece == nullptr)
        {
            getBoxPosibility(box,box->row+1 , box->column,possibilities);
            if(-1<box->row+2 && box->row+2<8 && boxes[box->row+2][box->column]->piece==nullptr && box->piece->move==1)
                getBoxPosibility(box,box->row+2 , box->column,possibilities);
        }
        //Ataque normal
        if(-1<box->row+1&&box->row+1<8)
        {
            if(-1<box->column-1&&box->column-1<8)
            {
                Box * diagLeft = this->boxes[box->row+1][box->column-1];
                if(diagLeft->piece != nullptr)
                {
                    getBoxPosibility(box,box->row+1 , box->column-1, possibilities);
                }
            }
            if(-1<box->column+1&&box->column+1<8)
            {
                Box * diagRight = this->boxes[box->row+1][box->column+1];
                if(diagRight->piece != nullptr)
                {
                    getBoxPosibility(box,box->row+1 , box->column+1, possibilities);
                }
            }
        }
        //Captura al paso
        if(box->row == 4 && box->piece->move == 3)
        {
            //Izquierda
            if(-1<box->column-1 && box->column-1>8)
            {
                Box * leftBox = this->boxes[box->row][box->column-1];
                if(leftBox->piece != nullptr && leftBox->piece->getPiece().compare("pawn") == 0)
                {
                    Pawn * leftPawn = static_cast<Pawn*>(leftBox->piece);
                    std::cout<<"Peon: Izquierdo "<<leftPawn->getPiece()<<std::endl;
                    if(leftPawn->vulnerableCapturaPaso)
                    {
                        std::cout<<"Peon izquierdo vulnerable a captura"<<std::endl;
                        getBoxPosibility(box , box->row+1 , box->column-1 , possibilities);
                        this->boxes[box->row+1][box->column-1]->markDangerBox();
                    }
                }
            }
            //Derecha
            if(-1<box->column+1&&box->column+1<8)
            {
                Box * rightBox = this->boxes[box->row][box->column+1];
                if(rightBox->piece != nullptr && rightBox->piece->getPiece().compare("pawn") == 0)
                {
                    Pawn * rightPawn = static_cast<Pawn*>(rightBox->piece);
                    std::cout<<"Peon: Derecho "<<rightPawn->getPiece()<<std::endl;
                    if(rightPawn->vulnerableCapturaPaso)
                    {
                        std::cout<<"Peon derecho vulnerable a captura"<<std::endl;
                        getBoxPosibility(box , box->row+1 , box->column+1 , possibilities);
                        this->boxes[box->row+1][box->column+1]->markDangerBox();
                    }
                }
            }
        }
    }
    else
    {
      getBoxPosibility(box,box->row-1 , box->column,possibilities);

      //Ataque del peon
      Box * diagLeft = this->boxes[box->row-1][box->column-1];
      if(diagLeft->piece != nullptr)
          getBoxPosibility(box,box->row-1 , box->column-1,possibilities);

      Box * diagRight = this->boxes[box->row-1][box->column+1];
      if(diagRight->piece != nullptr)
         getBoxPosibility(box,box->row-1 , box->column+1,possibilities);

      if(box->piece->move == 1)
      {
        getBoxPosibility(box,box->row-2 , box->column,possibilities);
      }
    }
  }
   if(box->piece->getPiece().compare("horse")==0)
   {
         getBoxPosibility(box,box->row+2 , box->column+1,possibilities);
         getBoxPosibility(box,box->row+2 , box->column-1,possibilities);
         getBoxPosibility(box,box->row-2 , box->column+1,possibilities);
         getBoxPosibility(box,box->row-2 , box->column-1,possibilities);

         getBoxPosibility(box,box->row+1 , box->column+2,possibilities);
         getBoxPosibility(box,box->row+1 , box->column-2,possibilities);
         getBoxPosibility(box,box->row-1 , box->column+2,possibilities);
         getBoxPosibility(box,box->row-1 , box->column-2,possibilities);
   }
   if(box->piece->getPiece().compare("king")==0)
   {
      comprobeMoveKing(box->row , box->column+1,possibilities);
       comprobeMoveKing(box->row , box->column-1,possibilities);
      comprobeMoveKing(box->row+1 , box->column,possibilities);
       comprobeMoveKing(box->row-1 , box->column,possibilities);
       comprobeMoveKing(box->row+1 , box->column+1,possibilities);
      comprobeMoveKing(box->row+1 , box->column-1,possibilities);
      comprobeMoveKing(box->row-1 , box->column+1,possibilities);
       comprobeMoveKing(box->row-1 , box->column-1,possibilities);
       /*
       //Posiblidad de enroque
       if(box->column>3&&box->column<6){
               //Posiblidad de enroque corto
        if(boxes[box->row][box->column+1]->piece==nullptr && boxes[box->row][box->column+2]->piece==nullptr)
        {
           markCastling(box->row,box->column+3);
           castling=true;
        }
            //Posiblidad de enroque largo
        if(boxes[box->row][box->column-1]->piece==nullptr && boxes[box->row][box->column-2]->piece==nullptr && boxes[box->row][box->column-3]->piece==nullptr)
        {
           markCastling(box->row,box->column-4);
           castling=true;
        }

      }
      */

   }
   if(box->piece->getPiece().compare("bishop")==0||box->piece->getPiece().compare("queen")==0)
   {
       //Moviendonos en la diagonal inferior derecha
       for(int i=1;i<8;i++)
       {
          if(box->column+i<8 &&box->row+i<8)
          {
              if(this->boxes[box->row+i][box->column+i]->piece!=nullptr)
              {
                getBoxPosibility(box,box->row+i,box->column+i,possibilities);
                  break;
              }
               getBoxPosibility(box,box->row+i,box->column+i,possibilities);
          }
       }
        //Moviendonos en la diagonal inferior izquierda
       for(int i=1;i<8;i++)
       {
           if(box->column-i>-1&&box->row+i<8)
           {
               if(this->boxes[box->row+i][box->column-i]->piece!=nullptr){
                  getBoxPosibility(box,box->row+i,box->column-i,possibilities);
                    break;
               }
              getBoxPosibility(box,box->row+i , box->column-i,possibilities);
           }
       }
        //Moviendonos en la diagonal superior derecha
       for(int i=1;i<8;i++)
       {
           if(box->row-i>-1&&box->column+i<8)
           {
               if(this->boxes[box->row-i][box->column+i]->piece!=nullptr){

                  getBoxPosibility(box,box->row-i,box->column+i,possibilities);
                   break;
               }
                getBoxPosibility(box,box->row-i ,box->column+i,possibilities);
           }
       }
       //Moviendonos en la diagonal superior izquierda
       for(int i=1;i<8;i++)
       {
           if(box->row-i>-1&&box->column-i>-1)
           {
               if(this->boxes[box->row-i][box->column-i]->piece!=nullptr)
               {
                   getBoxPosibility(box,box->row-i,box->column-i,possibilities);
                     break;
               }
              getBoxPosibility(box,box->row-i ,box->column-i,possibilities);
           }
       }
   }
   if(box->piece->getPiece().compare("tower")==0||box->piece->getPiece().compare("queen")==0)
   {
       //Moviendonos en la  misma columna hacia arriba
       for(int i=1;i<8;i++)
       {
           if(box->row+i<8)
           {
               if(this->boxes[box->row+i][box->column]->piece!=nullptr){
                   getBoxPosibility(box,box->row+i,box->column,possibilities);
                   break;
               }
               getBoxPosibility(box,box->row+i ,box->column,possibilities);
           }
       }
        //Moviendonos en la  misma columna hacia abajo
       for(int i=1;i<8;i++)
       {
           if(box->row-i>-1)
           {
               if(this->boxes[box->row-i][box->column]->piece!=nullptr)
               {
                   getBoxPosibility(box,box->row-i,box->column,possibilities);
                    break;
               }
              getBoxPosibility(box,box->row-i ,box->column,possibilities);
           }
       }
       //Moviendonos en la  misma fila hacia arriba
       for(int i=1;i<8;i++)
       {
           if(box->column+i<8)
           {
               if(this->boxes[box->row][box->column+i]->piece!=nullptr)
               {
                    //Posiblidad de enroque largo
                   if((box->piece->getPiece().compare("tower")==0)&&i==4)
                   {
                       castling=true;
                       markCastling(box->row,box->column+i);
                   }
                   getBoxPosibility(box,box->row,box->column+i,possibilities);
                     break;
               }
              getBoxPosibility(box,box->row,box->column+i,possibilities);
           }
       }
         //Moviendonos en la  misma fila hacia abajo
       for(int i=1;i<8;i++)
       {
           if(box->column-i>-1)
           {
               if(this->boxes[box->row][box->column-i]->piece!=nullptr)
               {
                   //Posiblidad de enrroque corto
                   if((box->piece->getPiece().compare("tower")==0)&&i==3)
                   {
                       castling=true;
                       markCastling(box->row,box->column-i);

                   }
                   getBoxPosibility(box,box->row,box->column-i,possibilities);
                   break;
               }
               getBoxPosibility(box,box->row,box->column-i,possibilities);
           }
       }

   }
   return possibilities;
}
void Board::selectBox(Box * box)
{
  if(box != this->boxSelected && box->piece != nullptr)
  {
    if((box->piece->color.compare("white")==0&&turn==0)||(box->piece->color.compare("black")==0&&turn==1))
    {
      this->boxSelected = box;
      //std::string pieza = box->piece->getPiece();
      if(jaque)
      {

      }
      else
      {
          std::vector<Box*> tmp=getPosibilities(boxSelected);
          for(size_t i=0;i<tmp.size();i++)
          {
            std::cout<<tmp[i]->row<<","<<tmp[i]->column<<std::endl;
          }
          std::cout<<tmp.size()<<"----------------"<<std::endl;
           showPossibilities(tmp);
      }
    }
  }
}
void Board::moveBox(Box * otherBox)
{
  //Si el box seleccionado no es el mismo y tampoco esta libre
  if(otherBox != this->boxSelected && otherBox->libre)
  {
    if(castling)
    {
        if(otherBox->piece->getPiece().compare("king")==0)
        {
            if(boxSelected->column==7){
                Castling(otherBox,0);
            }
            else
            {
               Castling(otherBox,1);
            }

        }
       else if(otherBox->piece->getPiece().compare("tower")==0)
        {
           if(otherBox->column==7)
           {
               Castling(otherBox,1);

           }
           else
           {
               Castling(otherBox,2);
           }

        }
        castling=false;
    }

    else
    {
        //Actualizamos el numero de movimientos
        boxSelected->piece->move++;
        verificarCapturaPeon(this->boxSelected , otherBox);
        //Actualizamos la posicion de las ficha a la casilla movida
        boxSelected->piece->row=otherBox->row;
        boxSelected->piece->column=otherBox->column;
         //Actualizamos los punteros de las piezas
        if(otherBox->piece!=nullptr)
        {
            removePiece(otherBox->piece);
        }
        otherBox->piece = boxSelected->piece;

        //std::cout<<"Posicion de la ficha seleccionada: "<<otherBox->piece->row<<","<<otherBox->piece->column<<std::endl;
        //std::cout<<"Posicion de la ficha: "<<otherBox->piece->row<<","<<otherBox->piece->column<<std::endl;



        //
        //boxSelected=otherBox;
        //std::cout<<"Pieza: "<<boxSelected->piece->getPiece()<<"Fila: "<<boxSelected->row<<"Columna: "<<boxSelected->column<<std::endl;
        //Mostramos los iconos de las piezas
        otherBox->setIcon(QIcon(otherBox->piece->imagen));
        this->boxSelected->setIcon(QIcon());
        otherBox->setIconSize(QSize(50,50));
        //Verificamos si el lugar donde cayo ameza la pisicion del rey enemigo
        std::vector<Box*> tmp=getPosibilities(otherBox);
        jaqueVerification(tmp);
        if(jaque)
        {
            DeathRoad=tmp;
        }



        this->boxSelected->piece = nullptr;
        //Marcamos como vulnerable por "captura por paso" al peon que haga su primera jugada con dos saltos
        if(otherBox->piece->getPiece().compare("pawn")==0)
        {
            Pawn * peon = static_cast<Pawn*>(otherBox->piece);
            if(otherBox->piece->move==2 && (otherBox->row==3 || otherBox->row==4))
                peon->vulnerableCapturaPaso = true;
            else
                peon->vulnerableCapturaPaso = false;
        }
    }
    this->boxSelected = nullptr;

    //Recargamos las celdas a su estado original
    bloquearCeldas();
    //Cambiamos el turno
    changeTurn();

  }
  else
  {
    std::cout<<"Se deja de seleccionar la pieza actual"<<std::endl;
    //Bloqueamos todas las celdas
    bloquearCeldas();
    this->boxSelected = nullptr;
  }
  //possibilities.clear();
}
void Board::Castling(Box * otherBox,int variant)
{
    int first=0,second=0;
    if(variant==0)
    {

       first=2;
       second=1;
         std::cout<<"Entro aqui if  "<<otherBox->column<<" "<<first<<" "<<otherBox->column+first<<std::endl;

    }
    else if(variant==1)
    {
        first=-2;
        second=-1;
    }

    else
    {
        first=3;
        second=2;
    }
    std::cout<<"if  "<<otherBox->column<<" "<<first<<" "<<otherBox->column+first<<std::endl;

    std::cout<<" Fila: "<<otherBox->row<<" Columna: "<<otherBox->column+first<<" Nombre: "<<otherBox->piece->getPiece()<<std::endl;
    std::cout<<" Fila: "<<otherBox->row<<" Columna: "<<otherBox->column+second<<" Nombre: "<<boxSelected->piece->getPiece()<<std::endl;

    boxes[otherBox->row][otherBox->column+first]->piece=otherBox->piece;
    boxes[otherBox->row][otherBox->column+second]->piece=boxSelected->piece;


    boxes[otherBox->row][otherBox->column+first]->setIcon(QIcon(otherBox->piece->imagen));
    boxes[otherBox->row][otherBox->column+second]->setIcon(QIcon(boxSelected->piece->imagen));
    this->boxSelected->setIcon(QIcon());
    otherBox->setIcon(QIcon());
    std::cout<<"ENtra: "<<std::endl;

    this->boxSelected->piece = nullptr;
    otherBox->piece=nullptr;
}
void Board::changeTurn()
{
    //Cambiamos el turno
    if(turn==0)
    {
        turn=1;
    }
    else
    {
        turn=0;
    }
}
Box* Board::getBoxSelected()
{
  return this->boxSelected;
}
void Board::showPossibilities(std::vector<Box*> possibilities)
{
    for(std::size_t i=0;i<possibilities.size();i++)
    {

        if(possibilities[i]->piece!=nullptr)
        {

            possibilities[i]->markDangerBox();
        }
        else
        {

            possibilities[i]->markBox();
        }
        possibilities[i]->libre=true;
    }
    possibilities.clear();
}
void Board::jaqueVerification(std::vector<Box*> possibilities)
{
    for(std::size_t i=0;i<possibilities.size();i++)
    {
        if(possibilities[i]->piece!=nullptr)
        {
           if(possibilities[i]->piece->getPiece().compare("king")==0)
           {
               jaque=true;
               QMessageBox msgBox;
               std::string msg;
               if(turn==0)
               {
                    msgBox.setText("Jaque a las blancas");
               }
               else
               {
                   msgBox.setText("Jaque a las negras");
               }


               msgBox.setStandardButtons(QMessageBox::Ok);
               msgBox.exec();
           }
        }

    }

}
void Board::removePiece(Piece *piece)
{
    if(turn==0)
    {
        for(size_t i=0;i<blackPieces.size();i++)
        {

            if(piece->row==blackPieces[i]->row&&piece->column==blackPieces[i]->column)
            {
                blackPieces.erase(blackPieces.begin() + i, blackPieces.begin() + (i+1));
                return;
            }
        }
    }
    else
    {
        for(size_t i=0;i<whitePieces.size();i++)
        {
            if(piece->row==whitePieces[i]->row&&piece->column==whitePieces[i]->column)
            {
               whitePieces.erase(whitePieces.begin() + i, whitePieces.begin() + (i+1));
                return;
            }
        }

    }
}
void Board::comprobeMoveKing(int row, int col,std::vector<Box*> &possibilities)
{

    if(turn==0)
    {
        for(size_t i=0;i<blackPieces.size();i++)
        {
            std::vector<Box*> tmp=getPosibilities(boxes[blackPieces[i]->row][blackPieces[i]->column]);
              std::cout<<blackPieces[i]->getPiece()<<" pisibilidades:"<<tmp.size()<<std::endl;
            for(size_t j=0;j<tmp.size();j++)
            {
                 std::cout<<tmp[j]->row<<","<<tmp[j]->column<<std::endl;
                if(row==tmp[j]->row&&tmp[j]->column==col)
                {
                    std::cout<<"Se elimino una posibilidad"<<std::endl;
                    return;
                }
            }
        }
    }
    else
    {
        for(size_t i=0;i<whitePieces.size();i++)
        {
            std::vector<Box*> tmp=getPosibilities(boxes[whitePieces[i]->row][whitePieces[i]->column]);
            for(size_t j=0;j<tmp.size();j++)
            {
                if(row==tmp[j]->row&&tmp[j]->column==col)
                {
                    return;
                }

            }
        }
    }
    getBoxPosibility(boxSelected,row,col,possibilities);

}
void Board::verificarCapturaPeon(Box* box, Box* otherBox)
{
  //Si ambos son piezas "peones"
  if(box->piece->getPiece().compare("pawn")==0 && otherBox->piece == nullptr)
  {
    Box * posiblePeon = this->boxes[box->row][otherBox->column];
    //Para las piezas blancas
    if(posiblePeon->piece != nullptr && posiblePeon->piece->getPiece().compare("pawn")==0 && box->column!=otherBox->column)
    {
        if(box->row == 4 && otherBox->row == 5)
        {
            std::cout<<"Hay captura de pieza"<<std::endl;
            this->boxes[box->row][otherBox->column]->piece = nullptr;
            this->boxes[box->row][otherBox->column]->setIcon(QIcon());
        }
        //Para las piezas negras
        else if(box->row == 3 && otherBox->row == 2)
        {
            std::cout<<"Hay captura pieza"<<std::endl;
            this->boxes[box->row][otherBox->column]->piece = nullptr;
            this->boxes[box->row][otherBox->column]->setIcon(QIcon());
        }
        else
        {
            std::cout<<"No hay captura al paso"<<std::endl;
        }
    }
  }
}
