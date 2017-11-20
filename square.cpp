#include "square.h"
#include "gui_game.h"
#include <QBrush>
#include <iostream>

extern Gui_Game* gui_game;

Square::Square(int i, int j, int size, QString colour)
{
    setRect(i,j,size,size);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if (colour == "black"){
        brush.setColor(Qt::darkGray);
    }else{
        brush.setColor(Qt::lightGray);
    }
    setBrush(brush);

}

void Square::setImg(QString path, int x, int y)
{
    img = new QGraphicsPixmapItem(path);
    img->setPos(x,y);
    img->setScale(0.27);
    img->setZValue(1);
    gui_game->scene->addItem(img);

}

void Square::removeImg()
{
    std::cout << "Square::removeImg()" << std::endl;
    gui_game->scene->removeItem(this->img);
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clickedS(this);
}
//#include "square.moc"
