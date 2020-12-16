#ifndef PIECE_H
#define PIECE_H

#include<QPainter>
#include<QWidget>

#include <string>

class Piece : public QWidget
{
  Q_OBJECT
public:
  Piece(QWidget * parent = nullptr);
  QString color;
  QPixmap imagen;
  int move=1;

  virtual std::string getPiece() = 0;
  std::string getColor();
};

#endif // PIECE_H
