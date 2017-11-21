#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "gui_board.h"

/*Gui_Game class keeps track of the entire state of the game.
 *
*/

class Gui_Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Gui_Game(QWidget* parent = NULL);

    //methods
    QString getWhosTurn();
    bool getPieceToMove();
    QString getPathPieceToMove();
    void setWhosTurn(QString player);
    void setPieceToMove(bool pickedUp);
    void setPathPieceToMove(QString path);
    void displayMainMenu();
    void setCursor(QString filename);
    void changePlayer();

    //events
    void mouseMoveEvent(QMouseEvent *event);

    //attributes
    QGraphicsScene* scene;
    ChessBoard* board;
    QGraphicsPixmapItem *cursor;


public slots:
   void start();
   void opponentMenu();

private:
   //methods
   void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
   void drawGUI();
   //attributes
   QString whosTurn;
   QGraphicsTextItem* whosTurnText;
   bool pieceToMove; // true if a piece was chosen
   QString pathPieceToMove; //folder path to the img. of the chosen piece

};
