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
    ui->gView->setScene(m_scene);
    m_scene->setBackendGraph(new Graph{"testnetwork/nodes.txt", "testnetwork/edges.txt"});
    m_scene->setBackgroundBrush(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnDraw_clicked()
{
    // static uint32_t nodeCounter = 1;
    // addNode(QString::number(nodeCounter));
    // ++nodeCounter;
}

void MainWindow::on_btnEdge_clicked() {}

void MainWindow::showGraph()
{
}

void MainWindow::addNode(const QString &nodeName)
{
    // NodeGraphicsItem *node = new NodeGraphicsItem{nodeName, -200, 200, 40};
    // m_scene->addItem(node);
    // m_scene->backend()
    // m_scene->backend().moveBy20X10Y();
}
