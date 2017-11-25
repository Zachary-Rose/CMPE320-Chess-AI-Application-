#include "show_dead.h"
#include "move.h"
#include "gui_game.h"

// TODO: for testing
#include <iostream>

ShowDead::ShowDead()
{
  // TODO: For some simple testing...
  Move m1(1, 1, 2, 1, 'Q');
  AddPiece(m1);
  Move m2(1, 1, 2, 1, 'n');
  AddPiece(m2);
}
extern Gui_Game* gui_game;

void ShowDead::AddPiece(Move move) //adds taken pieces to QLists based on white or black
{
	char deadPiece = move.GetCapturedPiece();
	if (deadPiece >= 97 && deadPiece <= 122)
  {
    // deadPiece is lowecase, add to black
		DeadBlack.append(deadPiece);
	}
	else
  {
    // deadpiece is uppercase, add to white
		DeadWhite.append(deadPiece);
	}

  Render();
}

void ShowDead::Render() //shows taken pieces Images
{
  std::cout << "SHOW DEAD" << std::endl; 
	int i,j;//qlist index #s
	int blackPosition, whitePosition; // y position of pieces
	QString imgfile = "./chessImg/"; 
	for (i = 0; i < DeadBlack.length(); i++) {
		if (DeadBlack[i] == 'k')
			imgfile = imgfile + "BlackKingB.png";
		if (DeadBlack[i] == 'q')
			imgfile = imgfile + "BlackQueenB.png";
		if (DeadBlack[i] == 'b')
			imgfile = imgfile + "BlackBishopB.png";
		if (DeadBlack[i] == 'r')
			imgfile = imgfile + "BlackRookB.png";
		if (DeadBlack[i] == 'n')
			imgfile = imgfile + "BlackKnightB.png";
		if (DeadBlack[i] == 'p')
			imgfile = imgfile + "BlackPawnB.png";
		blackPosition = i * 45 + 100; //y position of pieces changes based on index # in qlist
		Image = new QGraphicsPixmapItem(imgfile);
		Image->setPos(140, blackPosition);
		Image->setScale(0.13);
		Image->setZValue(1);
		gui_game->scene->addItem(Image);
	}
	for (j = 0; j < DeadWhite.length(); j++) {
		if (DeadWhite[j] == 'K')
			imgfile = imgfile + "WhiteKingW.png";
		if (DeadWhite[j] == 'Q')
			imgfile = imgfile + "WhiteQueenW.png";
		if (DeadWhite[j] == 'B')
			imgfile = imgfile + "WhiteBishopW.png";
		if (DeadWhite[j] == 'R')
			imgfile = imgfile + "WhiteRookW.png";
		if (DeadWhite[j] == 'N')
			imgfile = imgfile + "WhiteKnightW.png";
		if (DeadWhite[j] == 'P')
			imgfile = imgfile + "WhitePawnW.png";
		whitePosition = j * 45 + 100; 
		Image = new QGraphicsPixmapItem(imgfile);
		Image->setPos(848, whitePosition);
		Image->setScale(0.13);
		Image->setZValue(1);
		gui_game->scene->addItem(Image);
	}
} 



