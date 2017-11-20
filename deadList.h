#pragma once

#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>
#include "gui_game.h"

class deadList {
public:
	deadList();
	void appendLists();
	void setImg();
private:
	QVector<char> deadBlack = {};
	QVector<char> deadWhite = {};
	QGraphicsPixmapItem* img;
	int i;
	int j;
};