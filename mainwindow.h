#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QComboBox>
#include "paintingwidget.h"
#include <utility>
#include <vector>
using std::pair;
using std::vector;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onComboBoxSelected(const QString &text);
private:
    QVBoxLayout *m_layout;
    QComboBox *m_combo_box;
    PaintingWidget *m_painting;
};

#endif // MAINWINDOW_H
