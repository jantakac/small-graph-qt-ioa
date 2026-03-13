#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <QObject>

class Graph : public QObject
{
    Q_OBJECT
public:
    explicit Graph(QObject *parent = nullptr);

signals:
};

#endif // GRAPH_HPP
