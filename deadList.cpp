#include "deadList.h"

deadList::deadList(){}
extern Gui_Game* gui_game;

void deadList::appendLists()
{
	char deadpiece = /*new dead piece*/'b';
	if (deadpiece == 'k' || deadpiece == 'q' || deadpiece == 'b' || deadpiece == 'r' || deadpiece == 'n' || deadpiece == 'p') {
		deadBlack.append(deadpiece);
	}
	else if (deadpiece == 'K' || deadpiece == 'Q' || deadpiece == 'B' || deadpiece == 'R' || deadpiece == 'N' || deadpiece == 'P') {
		deadWhite.append(deadpiece);
	}
}

void deadList::setImg()
{
	int i,j = 0;
	int startingBlack;
	QString pieceName = ":/chessImg/";
	while (deadBlack[i] != NULL) {
		startingBlack = i * 30 + 300;
		img = new QGraphicsPixmapItem(pieceName);
		img->setPos(850, startingBlack);
		img->setScale(0.27);
		img->setZValue(1);
		gui_game->scene->addItem(img);
		++i;
	}
	while (deadBlack[j] != NULL) {
		startingBlack = i * 30 + 300;
		img = new QGraphicsPixmapItem(pieceName);
		img->setPos(0, startingBlack);
		img->setScale(0.27);
		img->setZValue(1);
		gui_game->scene->addItem(img);
		++j;
	}

}
	


