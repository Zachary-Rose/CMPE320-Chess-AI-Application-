#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Square: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Square(int i, int j, int sizeS, QString colour);
    void setImg(QString path, int x, int y);
    void removeImg();
    QString getImgPath();
    void setImgPath(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int getI();
    int getJ();
    int getSize();

signals:
    void clickedS(Square* sq);

private:
    QGraphicsPixmapItem* img;
    QString imgPath;
    int i;
    int j;
    int size;
};
