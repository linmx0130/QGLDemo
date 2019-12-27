#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);
    m_painting = new PaintingWidget(this);
    m_layout->addWidget(m_painting);
}

MainWindow::~MainWindow()
{

}


