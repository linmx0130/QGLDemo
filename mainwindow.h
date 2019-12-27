#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVBoxLayout>
#include <QComboBox>
#include "paintingwidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QVBoxLayout *m_layout;
    PaintingWidget *m_painting;
};

#endif // MAINWINDOW_H
