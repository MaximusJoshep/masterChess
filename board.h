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
    void jaqueVerification(std::vector<Box*> possibilities);
    void removePiece(Piece* piece);
    void comprobeMoveKing(int row,int col,std::vector<Box*> &possibilities);
    void generateDeathRoad(Box* attacker, Box* king);
    std::vector<Box*> outJaquePossibilities(Box* box,std::vector<Box*>  &possibilities);
    bool comprobeJaqueMate();
    void verificarCapturaPeon(Box* box , Box* otherBox);

    //En este metodo llenaremos el vector con las casillas de


private:
    Ui::Board *ui;
    Box * boxes[8][8];
    int turn=1;
    Box * boxSelected = nullptr;

    std::vector<Box*> DeathRoad;

    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;
    //std::vector<Box*>possibilities;
    bool castling{false};
    bool jaque{false};

};


#endif // BOARD_H
