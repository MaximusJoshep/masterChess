#ifndef PIECE_H
#define PIECE_H

#include<QPainter>
#include<QWidget>

#include <string>

class Piece : public QWidget
{
  Q_OBJECT
public:
  Piece(int Row,int Col,QWidget * parent = nullptr);
  QString color;
  QPixmap imagen;
  int move=1;

  virtual std::string getPiece() = 0;
  std::string getColor();
  int row;
  int column;
  friend bool operator== (const Piece& a, const Piece& b)
  {
      if(a.row==b.row&&a.column==b.column)
      {
          return true;
      }
      return false;
  }
  friend bool operator!= (const Piece& a, const Piece& b)
  {
      return !(a==b);
  }
};

#endif // PIECE_H
