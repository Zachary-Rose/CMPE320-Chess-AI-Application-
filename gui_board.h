#pragma once
#include <QList>
#include <QObject>
#include "square.h"


/* ChessBoard contains a collection of Square objects.
 * - all 64 Square Objects are stored in 'squares' QList.
 * - placeSquares() is a function that gets called only one time at the beginning of the game.
*/

/*
class ChessBoard:public QObject{
    Q_OBJECT
*/
class ChessBoard{
public:
    ChessBoard();
    void placeSquares();
/*
public slots:
    void choosePiece();
*/
private:
    QList<Square*> squares;
    int size; // size of every individual square
};
