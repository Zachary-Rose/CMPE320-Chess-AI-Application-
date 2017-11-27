#include "show_dead.h"
#include "move.h"
#include "gui_game.h"
#include "common.h"
#include <QMessageBox>
// TODO: for testing
#include <iostream>

ShowDead::ShowDead()
{
  WhiteIndex = 0;
  BlackIndex = 0;
}

extern Gui_Game* gui_game;

void ShowDead::AddPiece(char deadPiece) //adds taken pieces to QLists based on white or black
{
  LOG_WARNING("deadPiece " << deadPiece);

  if (deadPiece == 'k')
  {
    QMessageBox msgBox;
    msgBox.setWindowTitle("White Wins!!!");
    msgBox.setText("White pieces have won the game.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
    exit(0);
  }
  else if (deadPiece == 'K')
  {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Black Wins!!!");
    msgBox.setText("Black pieces have won the game.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
    exit(0);
  }

	if (deadPiece >= 97 && deadPiece <= 122)
  {
    QString imgfile = "./chessImg/";
    WhiteIndex++;
    switch (deadPiece)
    {
      case 'k':
        imgfile = imgfile + "BlackKingB.png";
        break;
      case 'q':
        imgfile = imgfile + "BlackQueenB.png";
        break;
      case 'b':
        imgfile = imgfile + "BlackBishopB.png";
        break;
      case 'r':
        imgfile = imgfile + "BlackRookB.png";
        break;
      case 'n':
        imgfile = imgfile + "BlackKnightB.png";
        break;
      case 'p':
        imgfile = imgfile + "BlackPawnB.png";
        break;
    }
    int renderPosition = WhiteIndex * 45 + 20;
    QGraphicsPixmapItem* img = new QGraphicsPixmapItem(imgfile);
    img->setPos(140, renderPosition);
    img->setScale(0.13);
    img->setZValue(1);
    gui_game->scene->addItem(img);
	}
	else
  {
    QString imgfile = "./chessImg/";
    BlackIndex++;
    switch (deadPiece)
    {
      case 'K':
        imgfile = imgfile + "WhiteKingW.png";
        break;
      case 'Q':
        imgfile = imgfile + "WhiteQueenW.png";
        break;
      case 'B':
        imgfile = imgfile + "WhiteBishopW.png";
        break;
      case 'R':
        imgfile = imgfile + "WhiteRookW.png";
        break;
      case 'N':
        imgfile = imgfile + "WhiteKnightW.png";
        break;
      case 'P':
        imgfile = imgfile + "WhitePawnW.png";
        break;
    }
    int renderPosition = BlackIndex * 45 + 20;
    QGraphicsPixmapItem* img = new QGraphicsPixmapItem(imgfile);
    img->setPos(848, renderPosition);
    img->setScale(0.13);
    img->setZValue(1);
    gui_game->scene->addItem(img);
	}
}



