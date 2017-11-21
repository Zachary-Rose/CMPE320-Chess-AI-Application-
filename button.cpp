#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "gui_game.h"

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //draw the rect
    setRect(0,0,50,50);

    //colour the button
    QBrush brush;
    //brush.setStyle(Qt::SolidPattern);
    //brush.setColor(Qt::white);
    setBrush(brush);

    //draw the text
    text = new QGraphicsTextItem(name, this);
    text->setDefaultTextColor(Qt::white);
    QFont titleFontButton ("Cambria",15);
    text->setFont(titleFontButton);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

/*
void Button::hoverEnterEvent(QGraphicsSceneMouseEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}
void Button::hoverLeaveEvent(QGraphicsSceneMouseEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
*/
