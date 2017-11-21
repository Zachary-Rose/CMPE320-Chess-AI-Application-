#include "square.h"
#include "gui_game.h"
#include <QBrush>
#include <iostream>

extern Gui_Game* gui_game;

Square::Square(int x, int y, int sizeS, QString colour)
{
    i = x;
    j = y;
    size = sizeS;
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
    gui_game->scene->removeItem(this->img);
    imgPath = " ";
}

QString Square::getImgPath()
{
    return imgPath;
}

void Square::setImgPath(QString path)
{
    imgPath = path;
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clickedS(this);
}

int Square::getI()
{
    return i;
}

int Square::getJ()
{
    return j;
}
int Square::getSize()
{
    return size;
}

