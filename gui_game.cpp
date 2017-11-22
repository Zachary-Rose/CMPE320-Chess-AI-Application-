#include "gui_game.h"
#include "square.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>

Gui_Game::Gui_Game(QWidget *parent)
{
    //window settings
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 690);
    //scene settings
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,690);
    setScene(scene);
    //variable default
    pieceToMove = NULL;
    cursor = nullptr;
    setMouseTracking(true);
}

// Gui_Game::start() starts the Chess Game. It creates the board and draws the two pannels.
void Gui_Game::start()
{
    scene->clear();
    board = new ChessBoard();
    board->placeSquares();
    drawGUI();
    setCursor(":/images/chessImg/BlackPawn.png");
}

void Gui_Game::opponentMenu()
{
    scene->clear();
    //Create Title

    QGraphicsTextItem *titleA = new QGraphicsTextItem(QString("Chess"));
    QFont titleFontA ("Cambria",50);
    titleA->setFont(titleFontA);
    titleA->setDefaultTextColor(Qt::white);
    int titleAxPos = this->width()/2 -250;
    int titleAyPos = 75;
    titleA->setPos(titleAxPos,titleAyPos);
    titleA->setZValue(1);
    scene->addItem(titleA);

    QGraphicsTextItem *titleB = new QGraphicsTextItem(QString("By Team BuckHorn"));
    QFont titleFontB ("Cambria",15);
    titleB->setFont(titleFontB);
    titleB->setDefaultTextColor(Qt::white);
    int titleBxPos = this->width()/2 - 200;
    int titleByPos = 150;
    titleB->setPos(titleBxPos,titleByPos);
    titleB->setZValue(1);
    scene->addItem(titleB);

    //Create Title
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Select Game"));
    QFont titleFont("cosmic sans", 30);
    title->setFont(titleFont);
    int txPos = this->width() / 2 - title->boundingRect().width() / 2;
    int tyPos = 150;
    title->setPos(txPos, tyPos);
    scene->addItem(title);

    QGraphicsPixmapItem* item;
    QString path = ":/chessImg/MainWindowBackground.png";
    item = new QGraphicsPixmapItem(path);
    item->setScale(1);
    item->setZValue(-1);
    scene->addItem(item);

    //Create the Play Vs A.I Button
    Button *playVsAiButton = new Button(QString("Player vs Computer"));
    int bxPos = 850;
    int byPos = 450;
    playVsAiButton->setPos(bxPos, byPos);
    connect(playVsAiButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playVsAiButton);

    //Create the Play vs Player Button
    Button *playVsPlayerButton = new Button(QString("Player vs Player"));
    int qxPos = 850;
    int qyPos = 525;
    playVsPlayerButton->setPos(qxPos, qyPos);
    connect(playVsPlayerButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playVsPlayerButton);
}


void Gui_Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Gui_Game::drawGUI()
{
    drawPanel(0,0,192,690,Qt::darkCyan,1);
    drawPanel(832,0,192,690,Qt::darkCyan,1);

    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(QString("PLAYER1"));
    whosTurnText->setPos(490,0);
    scene->addItem(whosTurnText);

}

QString Gui_Game::getWhosTurn()
{
    return whosTurn;
}

void Gui_Game::setWhosTurn(QString player)
{
    whosTurn = player;
    whosTurnText->setPlainText(QString("Whos' turn: ") + player);
}

void Gui_Game::displayMainMenu()
{
    //Create Title

    QGraphicsTextItem *titleA = new QGraphicsTextItem(QString("Chess"));
    QFont titleFontA ("Cambria",50);
    titleA->setFont(titleFontA);
    titleA->setDefaultTextColor(Qt::white);
    int titleAxPos = this->width()/2 -250;
    int titleAyPos = 75;
    titleA->setPos(titleAxPos,titleAyPos);
    titleA->setZValue(1);
    scene->addItem(titleA);

    QGraphicsTextItem *titleB = new QGraphicsTextItem(QString("By Team BuckHorn"));
    QFont titleFontB ("Cambria",15);
    titleB->setFont(titleFontB);
    titleB->setDefaultTextColor(Qt::white);
    int titleBxPos = this->width()/2 - 200;
    int titleByPos = 150;
    titleB->setPos(titleBxPos,titleByPos);
    titleB->setZValue(1);
    scene->addItem(titleB);
\


    QGraphicsPixmapItem* item;
    QString path = ":/chessImg/MainWindowBackground.png";
    item = new QGraphicsPixmapItem(path);
   item->setScale(1);
   item->setZValue(-1);
   scene->addItem(item);


    //Create the Play Button
    Button *playButton = new Button(QString("Play"));
    int bxPos = 850;
    int byPos = 450;
    playButton->setPos(bxPos,byPos);
    //connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    connect(playButton, SIGNAL(clicked()),this,SLOT(opponentMenu()));

    scene->addItem(playButton);

    //Create the Quit Button
    Button *closeButton = new Button(QString("Quit"));
    int qxPos = 850;
    int qyPos = 525;
    closeButton->setPos(qxPos,qyPos);
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(closeButton);


}

void Gui_Game::setCursor(QString filename)
{
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Gui_Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}


