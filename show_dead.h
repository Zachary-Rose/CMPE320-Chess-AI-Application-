#pragma once

#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>

class Move;

class ShowDead {
public:
  ShowDead();
  void AddPiece(Move move);
	void Render();
private:
	QList<char> DeadBlack; //QList of taken black pieces
	QList<char> DeadWhite; //QList of taken white pieces
	QGraphicsPixmapItem* Image; 
};