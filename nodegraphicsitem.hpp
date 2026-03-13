#ifndef NODEGRAPHICSITEM_HPP
#define NODEGRAPHICSITEM_HPP

#include <QBrush>
#include <QGraphicsItem>
#include <QPen>

class NodeGraphicsItem : public QGraphicsEllipseItem
{
public:
    explicit NodeGraphicsItem(
        const QString &label, qreal x, qreal y, uint16_t size, QGraphicsItem *parent = nullptr);

private:
    QGraphicsTextItem *m_label;
    qreal m_x;
    qreal m_y;
    int16_t m_size;

    void initLabelPos();
};

#endif // NODEGRAPHICSITEM_HPP
