#include "graphscene.hpp"

GraphScene::GraphScene(QObject *parent)
    : QGraphicsScene{parent}

{}

void GraphScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->fillRect(rect, Qt::white);

    int32_t left = qFloor(rect.left() / gridSize) * gridSize;
    int32_t top = qFloor(rect.top() / gridSize) * gridSize;

    // 100 is on stack but if you unzoom too much it moves to the heap
    QVarLengthArray<QLine, 100> lines;

    for (int32_t x = left; x <= rect.right(); x += gridSize) {
        lines.append(QLine(x, (int) rect.top(), x, (int) rect.bottom()));
    }

    for (int32_t y = top; y <= rect.bottom(); y += gridSize) {
        lines.append(QLine((int) rect.left(), y, (int) rect.right(), y));
    }

    painter->setPen(QPen(Qt::black, 0));
    painter->drawLines(lines.data(), lines.size());
}

void GraphScene::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->setPen(QPen(Qt::black));
    QFont font = painter->font();
    font.setPointSize(8);
    painter->setFont(font);

    int32_t leftStart = qFloor(rect.left() / gridSize) * gridSize;
    int32_t topStart = qFloor(rect.top() / gridSize) * gridSize;

    for (int32_t x = leftStart; x <= rect.right(); x += gridSize) {
        painter->drawText(x + 2, rect.bottom() - 15, 50, 20, Qt::AlignLeft, QString::number(x));
    }

    for (int32_t y = topStart; y <= rect.bottom(); y += gridSize) {
        painter->drawText(rect.right() - 40, y + 2, 35, 20, Qt::AlignRight, QString::number(y));
    }
}
