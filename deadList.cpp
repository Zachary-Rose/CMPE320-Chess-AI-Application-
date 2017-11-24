#include "deadList.h"
#include "move.h"
#include "gui_board.h"
#include <iostream>

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
  std::cout << "SHOW DEAD" << std::endl;
	appendLists(); 
	int i,j;//qlist index #s
	int blackPosition, whitePosition; // y position of pieces
	QString imgfile = "./chessImg/"; 
	for (i = 0; i < deadBlack.length(); i++) {
		if (deadBlack[i] == 'k')
			imgfile = imgfile + "BlackKingB.png";
		if (deadBlack[i] == 'q')
			imgfile = imgfile + "BlackQueenB.png";
		if (deadBlack[i] == 'b')
			imgfile = imgfile + "BlackBishopB.png";
		if (deadBlack[i] == 'r')
			imgfile = imgfile + "BlackRookB.png";
		if (deadBlack[i] == 'n')
			imgfile = imgfile + "BlackKnightB.png";
		if (deadBlack[i] == 'p')
			imgfile = imgfile + "BlackPawnB.png";
		blackPosition = i * 45 + 100; //y position of pieces changes based on index # in qlist
		image = new QGraphicsPixmapItem(imgfile);
		image->setPos(140, blackPosition);
		image->setScale(0.13);
		image->setZValue(1);
		gui_game->scene->addItem(image);
	}
	for (j = 0; j < deadWhite.length(); j++) {
		if (deadWhite[j] == 'K')
			imgfile = imgfile + "WhiteKingW.png";
		if (deadWhite[j] == 'Q')
			imgfile = imgfile + "WhiteQueenW.png";
		if (deadWhite[j] == 'B')
			imgfile = imgfile + "WhiteBishopW.png";
		if (deadWhite[j] == 'R')
			imgfile = imgfile + "WhiteRookW.png";
		if (deadWhite[j] == 'N')
			imgfile = imgfile + "WhiteKnightW.png";
		if (deadWhite[j] == 'P')
			imgfile = imgfile + "WhitePawnW.png";
		whitePosition = j * 45 + 100; 
		image = new QGraphicsPixmapItem(imgfile);
		image->setPos(840, whitePosition);
		image->setScale(0.13);
		image->setZValue(1);
		gui_game->scene->addItem(image);
	}
} 



