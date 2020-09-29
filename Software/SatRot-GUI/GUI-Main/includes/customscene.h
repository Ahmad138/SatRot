#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QObject>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>

class CustomScene : public QGraphicsScene {
    Q_OBJECT


public:
    explicit CustomScene();
    QGraphicsLineItem *item;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) {

        item = new QGraphicsLineItem;
        addItem(item);
        const QPointF p = event->scenePos();

        item->setPos(p);
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
        const QPointF p = item->mapFromScene(event->scenePos());
//        QLineF l = item->line();
//        l.setP2(p);
//        item->setLine(l);

        QPainter painter;
        QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);

        painter.drawPoint(p);

        item->setPen(pen);

        // ...then check the bounds
//        if (x() < 0)
//            setPos(0, y());
//        else if (x() > 481)
//            setPos(481, y());

//        if (y() < 0)
//            setPos(x(), 0);
//        else if (y() > 270)
//            setPos(x(), 270);
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
        const QPointF p = item->mapFromScene(event->scenePos());
        QLineF l = item->line();
        l.setP2(p);
        item->setLine(l);
    }
};


#endif // CUSTOMSCENE_H
