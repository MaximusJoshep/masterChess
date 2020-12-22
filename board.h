#ifndef BOARD_H
#define BOARD_H
#include <box.h>
#include <QWidget>
#include <vector>
#include <iostream>
#include <piece.h>
#include <cstring>
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
    std::vector<Box*> getPosibilities(Box* box);
    void selectBox(Box * box);
    void moveBox(Box * otherBox);
    Box * getBoxSelected();
    void changeTurn();
    void getBoxPosibility(Box* box,int row , int col , std::vector<Box*> &possibilities);
    void getDangerPossibility(Box* box,int row , int col ,std::vector<Box*> &possibilities);
    void markCastling(int row , int col);
    void Castling(Box * otherBox,int variant);
    void showPossibilities(std::vector<Box*> possibilities);
    void jaqueVerification(Box* attacker);
    void removePiece(Piece* piece);
    void comprobeMoveKing(int row,int col,std::vector<Box*> &possibilities);
<<<<<<< HEAD
    void verificarCapturaPeon(Box* box , Box* otherBox);
=======
    void generateDeathRoad(Box* attacker, Box* king);
    std::vector<Box*> outJaquePossibilities(std::vector<Box*>  &possibilities);



>>>>>>> cee2930ec8ee391432250ff1d3ba8c5a08658edc
    //En este metodo llenaremos el vector con las casillas de


private:
    Ui::Board *ui;
    Box * boxes[8][8];
    int turn=0;
    Box * boxSelected = nullptr;
    Piece * attackingPiece;

    std::vector<Box*> DeathRoad;

    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;
    //std::vector<Box*>possibilities;
    bool castling{false};
    bool jaque{false};

};


#endif // BOARD_H
