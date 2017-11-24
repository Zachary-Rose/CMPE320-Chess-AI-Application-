#pragma once

#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>
#include "gui_game.h"

class deadList {
public:
	deadList();
	void appendLists(); 
	void showDead();
private:
	QList<char> deadBlack; //QList of taken black pieces
	QList<char> deadWhite; //QList of taken white pieces
	QGraphicsPixmapItem* image; 
};