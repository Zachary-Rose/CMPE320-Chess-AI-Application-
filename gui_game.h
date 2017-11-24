#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "gui_board.h"
#include "show_dead.h"

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
    int get_iSquareSelected();
    int get_jSquareSelected();
    char get_pieceToMoveChar();
    void setWhosTurn(QString player);
    void setPieceToMove(bool pickedUp);
    void setPathPieceToMove(QString path);
    void set_iSquareSelected(int x);
    void set_jSquareSelected(int y);
    void set_pieceToMoveChar(char c);
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
   void startAI();  // start player vs ai mode
   void startPP();  // start player vs player mode
   void opponentMenu();

private:
   //methods
   void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
   void drawGUI();
   //attributes
   QString playMode;
   QString whosTurn;
   QGraphicsTextItem* whosTurnText;
   bool pieceToMove; // true if a piece was chosen
   QString pathPieceToMove; //folder path to the img. of the chosen piece
   int iSquareSelected; // the i value of the square that the user clicked on
   int jSquareSelected; // the j value of the square that the user clicked on
   char pieceToMoveChar;
   ShowDead* showDead;
};
