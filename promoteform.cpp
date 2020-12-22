#include "promoteform.h"
#include "ui_promoteform.h"

#include "horse.h"
#include "bishop.h"
#include "tower.h"
#include "queen.h"

PromoteForm::PromoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PromoteForm)
{
    ui->setupUi(this);
}

PromoteForm::~PromoteForm()
{
    delete ui;
}
//Promovido a torre
void PromoteForm::on_pushButton_clicked()
{
    QString color = QString::fromStdString("white");
    if(this->turno != 0)
        color = QString::fromStdString("black");
    this->piecePromoted = new Tower(this->row , this->col , color , this->parentWidget());

}

//Promovido a alfil
void PromoteForm::on_pushButton_2_clicked()
{
    QString color = QString::fromStdString("white");
    if(this->turno != 0)
        color = QString::fromStdString("black");
    this->piecePromoted = new Bishop(this->row , this->col , color , this->parentWidget());

}

//Promovido a caballo
void PromoteForm::on_pushButton_3_clicked()
{
    QString color = QString::fromStdString("white");
    if(this->turno != 0)
        color = QString::fromStdString("black");
    this->piecePromoted = new Horse(this->row , this->col , color , this->parentWidget());
}

//Promovido a dama
void PromoteForm::on_pushButton_4_clicked()
{
    QString color = QString::fromStdString("white");
    if(this->turno != 0)
        color = QString::fromStdString("black");
    this->piecePromoted = new Queen(this->row , this->col , color , this->parentWidget());

}
Piece * PromoteForm::getPromotedPiece()
{
    return piecePromoted;
}
void PromoteForm::SetDataPromotion(int row, int col, QWidget* parent , int turno)
{
    this->row = row;
    this->col = col;
    this->pieceParent = parent;
    this->turno = turno;
}
