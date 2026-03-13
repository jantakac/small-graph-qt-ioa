#ifndef GRAPHSCENE_HPP
#define GRAPHSCENE_HPP

#include <QGraphicsScene>
#include <QVarLengthArray>
#include <qpainter.h>

class GraphScene : public QGraphicsScene
{
public:
    static constexpr int8_t gridSize = 50;
    explicit GraphScene(QObject *parent = nullptr);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;
};

#endif // GRAPHSCENE_HPP
