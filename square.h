#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

/*
class Square: public QObject, public QGraphicsRectItem{
    Q_OBJECT
*/
class Square: public QGraphicsRectItem{
public:
    Square(int i, int j, int size, QString colour);
    void setImg(QString path, int x, int y);
    void mousePressEventt(QGraphicsSceneMouseEvent *event);
/*
signals:
    void clickedS();
*/
private:
    QGraphicsPixmapItem* img;
    int i;
    int j;
    int size;
};
