#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);
    m_combo_box = new QComboBox(this);
    m_painting = new PaintingWidget(this);
    m_layout->addWidget(m_painting);
    m_layout->addWidget(m_combo_box);
    m_combo_box->addItem("Red");
    m_combo_box->addItem("Blue");
    m_combo_box->addItem("Yellow");
    m_combo_box->addItem("Green");
    connect(m_combo_box,
            SIGNAL(currentIndexChanged(const QString&)),
            this,
            SLOT(onComboBoxSelected(const QString&)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::onComboBoxSelected(const QString &text)
{
    if (text == "Red") {
        this->m_painting->setColor(1.0f, 0.0f, 0.0f);
    }
    if (text == "Blue") {
        this->m_painting->setColor(0.0f, 0.0f, 1.0f);
    }
    if (text == "Yellow") {
        this->m_painting->setColor(1.0f, 1.0f, 0.0f);
    }
    if (text == "Green") {
        this->m_painting->setColor(0.0f, 1.0f, 0.0f);
    }
}

