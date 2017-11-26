#pragma once

#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>

class Move;

class ShowDead {
public:
  ShowDead();
  void AddPiece(char deadPiece);
private:
  int WhiteIndex;
  int BlackIndex;
};