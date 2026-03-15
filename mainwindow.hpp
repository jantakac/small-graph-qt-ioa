#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QGraphicsScene>
#include <QMainWindow>
#include <QOpenGLWidget>

#include "graphscene.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnDraw_clicked();

    void on_btnEdge_clicked();

private:
    Ui::MainWindow *ui;
    GraphScene *m_scene;
    void showGraph();

    void addNode(const QString &nodeName);
};
#endif // MAINWINDOW_HPP
