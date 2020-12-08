#ifndef PIECE_H
#define PIECE_H

#include<QPainter>
#include<QWidget>
class Piece : public QWidget
{
  Q_OBJECT
public:
  Piece(QWidget * parent = nullptr);
  QString color;
  QPixmap imagen;
};

#endif // PIECE_H
