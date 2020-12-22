#ifndef PROMOTEFORM_H
#define PROMOTEFORM_H

#include <QWidget>

#include "piece.h"
#include "board.h"

namespace Ui {
class PromoteForm;
}

class PromoteForm : public QWidget
{
    Q_OBJECT

public:
    int row{} , col{} , turno{};
    QWidget * pieceParent;
    explicit PromoteForm(QWidget *parent = nullptr);
    ~PromoteForm();
    Piece * getPromotedPiece();
    void SetDataPromotion(int row, int col, QWidget* parent , int turno);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::PromoteForm *ui;
    Piece * piecePromoted;
};

#endif // PROMOTEFORM_H
