#include "gui_board.h"
#include "gui_game.h"
#include <QList>
#include <QBrush>
#include <QMouseEvent>
#include <iostream>
extern Gui_Game* gui_game;



ChessBoard::ChessBoard(){
    size = 80;

    // QList of string that contains the name of the Chess pieces in order that they will be displayed
    QList<QString> nameblack = {"BlackRook","BlackKnight","BlackBishop","BlackKing","BlackQueen","BlackBishop","BlackKnight","BlackRook"};
    QList<QString> namewhite = {"WhiteRook","WhiteKnight","WhiteBishop","WhiteKing","WhiteQueen","WhiteBishop","WhiteKnight","WhiteRook"};

    QString colour;
    for (size_t i = 0, n = 8; i < n; i++){
        for (size_t j = 0, n = 8; j < n; j++){
            //Choose the colour of the square (white / black).
            if ((i + j)%2 == 0){
                colour = "black";
            }else{
                colour = "white";
            }

            //Choose what piece will be placed in each square.
            QString pieceName = ":/chessImg/"; //path to the images in Resources folder.
            if (j == 0){
                pieceName = pieceName + nameblack[i];
            }else if(j == 1){
                pieceName = pieceName + "BlackPawn";
            }else if(j == 7){
                pieceName = pieceName + namewhite[i];
            }else if(j == 6){
                pieceName = pieceName + "WhitePawn";
            }else{
                pieceName = " ";
            }

            //Create the square.
            Square* square = new Square(i,j,size,colour);
            square->setPos(i*size + 192,j*size + 40);
            square->setImg(pieceName,i*size + 192,j*size + 40);
            square->setImgPath(pieceName);
            connect(square, SIGNAL(clickedS(Square *)),this,SLOT(pickUpPiece(Square *)));
            squares.append(square);
            gui_game->scene->addItem(square);
        }
    }
}

void ChessBoard::placeSquares()
{

}

void ChessBoard::pickUpPiece(Square *sq)
{
    if (gui_game->getPieceToMove()){ // a piece was previously selected
        if (sq->getImgPath() == " "){ // no image is present on this square
            QString path = gui_game->getPathPieceToMove();
            sq->setImg(path,sq->getI()*sq->getSize() + 192,sq->getJ()*sq->getSize() + 40);
            sq->setImgPath(path);
            gui_game->setPieceToMove(false);
            gui_game->setPathPieceToMove(" ");
            gui_game->setCursor(nullptr);
        }else{
            gui_game->setPieceToMove(true);
        }

    }else{ // a piece has not been selected yet
        gui_game->setPieceToMove(true);
        gui_game->setCursor(sq->getImgPath());
        gui_game->setPathPieceToMove(sq->getImgPath());
        sq->removeImg();
    }

    //std::cout << "ChessBoard::pickUPPiece(Square *sq)" << std::endl;

}


