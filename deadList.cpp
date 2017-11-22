#include "deadList.h"
#include "move.h"
#include "gui_board.h"

deadList::deadList(){}
extern Gui_Game* gui_game;

void deadList::appendLists() //adds taken pieces to QLists based on white or black
{

	char deadpiece = 'K'; //testing with a random piece. will be replaced with right piece from move.h
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
	int i,j;//qlist index #s
	int blackPosition, whitePosition; // y position of pieces
	QString imgfile = ":/chessImg/"; 
	for (i = 0; i < deadBlack.length(); i++) {
		if (deadBlack[i] == 'k')
			imgfile = imgfile + "BlackKing.png";
		if (deadBlack[i] == 'q')
			imgfile = imgfile + "BlackQueen.png";
		if (deadBlack[i] == 'b')
			imgfile = imgfile + "BlackBishop.png";
		if (deadBlack[i] == 'r')
			imgfile = imgfile + "BlackRook.png";
		if (deadBlack[i] == 'n')
			imgfile = imgfile + "BlackKnight.png";
		if (deadBlack[i] == 'p')
			imgfile = imgfile + "BlackPawn.png";
		blackPosition = i * 45 + 100; //y position of pieces changes based on index # in qlist
		image = new QGraphicsPixmapItem(imgfile);
		image->setPos(140, blackPosition);
		image->setScale(0.13);
		image->setZValue(1);
		gui_game->scene->addItem(image);
	}
	for (j = 0; j < deadWhite.length(); j++) {
		if (deadWhite[j] == 'K')
			imgfile = imgfile + "WhiteKing.png";
		if (deadWhite[j] == 'Q')
			imgfile = imgfile + "WhiteQueen.png";
		if (deadWhite[j] == 'B')
			imgfile = imgfile + "WhiteBishop.png";
		if (deadWhite[j] == 'R')
			imgfile = imgfile + "WhiteRook.png";
		if (deadWhite[j] == 'N')
			imgfile = imgfile + "WhiteKnight.png";
		if (deadWhite[j] == 'P')
			imgfile = imgfile + "WhitePawn.png";
		whitePosition = j * 45 + 100; 
		image = new QGraphicsPixmapItem(imgfile);
		image->setPos(840, whitePosition);
		image->setScale(0.13);
		image->setZValue(1);
		gui_game->scene->addItem(image);
	}
} 



