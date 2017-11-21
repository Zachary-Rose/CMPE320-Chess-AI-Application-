#include "deadList.h"
#include "move.h"
#include "gui_board.h"

deadList::deadList(){}
extern Gui_Game* gui_game;

void deadList::appendLists() //adds taken pieces to QLists based on white or black
{
	char deadpiece = 'k'; //testing with a random piece. will be replaced with right piece from move.h
	if (deadpiece == 'k' || deadpiece == 'q' || deadpiece == 'b' || deadpiece == 'r' || deadpiece == 'n' || deadpiece == 'p') {
		deadBlack.append(deadpiece);
	}
	else if (deadpiece == 'K' || deadpiece == 'Q' || deadpiece == 'B' || deadpiece == 'R' || deadpiece == 'N' || deadpiece == 'P') {
		deadWhite.append(deadpiece);
	}
}

void deadList::showDead() //shows taken pieces images
{
	appendLists(); 
	int i,j = 0;//qlist index #s
	int blackPosition, whitePosition; // y position of pieces
	QString imgfile = ":/chessImg/BlackBishop.png"; //testing with black bishop
	while (i<deadBlack.length()) { 
		blackPosition = i * 30 + 300; //y position of pieces changes based on index # in qlist
		image = new QGraphicsPixmapItem(imgfile);
		image->setPos(1, blackPosition);
		//image->setScale(0.27);
		image->setZValue(1);
		gui_game->scene->addItem(image);
		i++;
	}
	while (j<deadWhite.length()) {
		whitePosition = j * 30 + 300; 
		image = new QGraphicsPixmapItem(imgfile);
		image->setPos(0, whitePosition);
		//image->setScale(0.27);
		image->setZValue(1);
		gui_game->scene->addItem(image);
		j++;
	}

}
	


