#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui{new Ui::MainWindow}
    , m_scene{new GraphScene{this}}
{
    ui->setupUi(this);
    ui->gView->setViewport(new QOpenGLWidget{});
    ui->gView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->gView->setRenderHint(QPainter::Antialiasing);
    ui->gView->setScene(m_scene);
    m_scene->setBackendGraph(new Graph{"testnetwork/nodes.txt", "testnetwork/edges.txt"});
    m_scene->setBackgroundBrush(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRotate_clicked()
{
    m_scene->backend().rotateBy90Degrees();
}

void MainWindow::on_btnMove_clicked()
{
    m_scene->backend().moveBy20X10Y();
}
