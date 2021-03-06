#include "gui_board.h"
#include "gui_game.h"
#include "move.h"
#include "board.h"
#include "ai.h"
#include "board_position.h"
#include <QList>
#include <QBrush>
#include <QMouseEvent>
#include <QMessageBox>

extern Gui_Game* gui_game;
extern Ai* gui_ai;

ChessBoard::ChessBoard(){
    size = 80;

    // QList of string that contains the name of the Chess pieces in order that they will be displayed
    QList<QString> nameblack = {"BlackRook","BlackKnight","BlackBishop","BlackQueen","BlackKing","BlackBishop","BlackKnight","BlackRook"};
    QList<QString> namewhite = {"WhiteRook","WhiteKnight","WhiteBishop","WhiteQueen","WhiteKing","WhiteBishop","WhiteKnight","WhiteRook"};

    QString colour;
    for (short i = 7; i >= 0; i--)
    {
        for (short j = 7; j >= 0; j--)
        {
            //Choose the colour of the square (white / black).
            if ((i + j)%2 == 0)
            {
                colour = "white";
            }
            else
            {
                colour = "black";
            }

            //Choose what piece will be placed in each square.
            QString pieceName = "./chessImg/"; //path to the images in Resources folder.
            if (j == 0)
            {
                pieceName = pieceName + nameblack[i] + "B";
            }
            else if(j == 1)
            {
                pieceName = pieceName + "BlackPawn" + "B";
            }
            else if (j == 6)
            {
              pieceName = pieceName + "WhitePawn" + "W";
            }
            else if(j == 7)
            {
                pieceName = pieceName + namewhite[i] + "W";
            }else{
                pieceName = " ";
            }

            LOG_INFO("piece: " << pieceName.toStdString() << " i: " << i << " j: " << j);

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

/*
void ChessBoard::placeSquares()
{

}*/

char ChessBoard::getCharfromPath(QString path)
{
    //std::cout <<path.mid(11,path.size()-12).toUtf8().constData()<<std::endl;
    QString pieceName = path.mid(11,path.size()-12);
    if (pieceName == "BlackKing"){
        return B_KING;
    }else if (pieceName == "BlackQueen"){
        return B_QUEEN;
    }else if (pieceName == "BlackBishop"){
        return B_BISHOP;
    }else if (pieceName == "BlackRook"){
        return B_ROOK;
    }else if (pieceName == "BlackKnight"){
        return B_KNIGHT;
    }else if (pieceName == "BlackPawn"){
        return B_PAWN;
    }else if (pieceName == "WhiteKing"){
        return W_KING;
    }else if (pieceName == "WhiteQueen"){
        return W_QUEEN;
    }else if (pieceName == "WhiteBishop"){
        return  W_BISHOP;
    }else if (pieceName == "WhiteRook"){
         return W_ROOK;
    }else if (pieceName == "WhiteKnight"){
        return W_KNIGHT;
    }else if (pieceName == "WhitePawn"){
        return W_PAWN;
    }else{
      return EMPTY;
    }
}

void ChessBoard::showAiMove(Move toMove)
{
    BoardPosition from = toMove.GetFromPiecePosition();
    BoardPosition to = toMove.GetToPiecePosition();
    int fromI =   from.i();
    int fromJ = from.j();
    int toI = to.i();
    int toJ = to.j();
    char piece = toMove.GetCapturedPiece();

}

Square* ChessBoard::getSquare(int i, int j)
{
    foreach (Square* sq, squares) {
       int x = sq->getI();
       int y = sq->getJ();
       if (x == i && y == j){
           return sq;
       }
    }
}

void ChessBoard::pickUpPiece(Square *sq)
{
    if (gui_game->getPieceToMove()){ // a piece was previously selected
        QString path = gui_game->getPathPieceToMove();
        int x1 = gui_game->get_iSquareSelected();
        int y1 = gui_game->get_jSquareSelected();

        int x2 = sq->getI();
        int y2 = sq->getJ();
        char c = gui_game->get_pieceToMoveChar();
        Move moveObj = Move(y1,x1,y2,x2,c);

        if (x1 == x2 && y1 == y2)
        {
          sq->removeImg(); // delete the piece that is curently on the square
          sq->setImg(path, sq->getI()*sq->getSize() + 192, sq->getJ()*sq->getSize() + 40);
          sq->setImgPath(path);
          gui_game->setPieceToMove(false);
          gui_game->setPathPieceToMove(" ");
          gui_game->setCursor(nullptr);
          gui_game->set_pieceToMoveChar(EMPTY);
          gui_ai->ExecuteMove(moveObj);
        }
        else if (gui_ai->IsMoveLegal(moveObj))
        {
          char takenChar = getCharfromPath(sq->getImgPath());
          gui_game->addDeadPiece(takenChar);
            sq->removeImg(); // delete the piece that is curently on the square
            sq->setImg(path,sq->getI()*sq->getSize() + 192,sq->getJ()*sq->getSize() + 40);
            sq->setImgPath(path);
            gui_game->setPieceToMove(false);
            gui_game->setPathPieceToMove(" ");
            gui_game->setCursor(nullptr);
            gui_game->changePlayer();
            gui_game->set_pieceToMoveChar(EMPTY);
            gui_ai->ExecuteMove(moveObj);
        }else
        {
          QMessageBox msgBox;
          msgBox.setWindowTitle("Illegal Move");
          msgBox.setText("That is not a valid chess move.");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();
        }

    }else{ // a piece has not been selected yet
        //QStringRef subString(sq->getImgPath(),5,2);
        QString col;
        col = sq->getImgPath().mid(sq->getImgPath().size()-1,1); // gets the colour of the piece (the last letter in the path name)
        if (sq->getImgPath() != " "){
            if ((col == "B" && gui_game->getWhosTurn() == "BLACK")||(col == "W" && gui_game->getWhosTurn() == "WHITE")){
                gui_game->setPieceToMove(true);
                gui_game->setCursor(sq->getImgPath());
                gui_game->setPathPieceToMove(sq->getImgPath());
                gui_game->set_iSquareSelected(sq->getI());
                gui_game->set_jSquareSelected(sq->getJ());
                gui_game->set_pieceToMoveChar(getCharfromPath(sq->getImgPath()));
                sq->removeImg();
            }
        }
    }

}


