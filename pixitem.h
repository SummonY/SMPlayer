#ifndef PIXITEM_H
#define PIXITEM_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class PixItem : public QGraphicsItem,public QObject
{
public:
    PixItem(QPixmap *pixmap);

    QRectF boundingRect() const;                            //define bounding function
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap pix;
};

#endif // PIXITEM_H
