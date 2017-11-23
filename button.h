#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsRectItem{
  Q_OBJECT
public:
    //constructor
    Button(QString name, QGraphicsItem* parent = NULL);
    //methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void hoverEnterEvent(QGraphicsSceneMouseEvent *event);
    //void hoverLeaveEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};
