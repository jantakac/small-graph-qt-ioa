#include "nodegraphicsitem.hpp"
#include <qfont.h>

NodeGraphicsItem::NodeGraphicsItem(
    const QString &label, qreal x, qreal y, uint16_t size, QGraphicsItem *parent)
    : QGraphicsEllipseItem(0, 0, size, size, parent)
    , m_label(new QGraphicsTextItem{label, this})
    , m_x(x)
    , m_y(y)
    , m_size(size)
{
    setFlags(ItemIsSelectable);
    setBrush(QBrush{Qt::yellow});
    setPen(QPen{Qt::black});
    setPos(m_x - m_size / 2, m_y - m_size / 2);
    initLabelPos();
}

void NodeGraphicsItem::initLabelPos()
{
    if (!m_label)
        return;

    QFont font = m_label->font();
    font.setPointSize(m_size / 2);
    m_label->setFont(font);

    m_label->setPos(m_size / 2 - m_label->boundingRect().width() / 2,
                    m_size / 2 - m_label->boundingRect().height() / 2);
}
