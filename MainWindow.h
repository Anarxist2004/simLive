#pragma once
#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>

class MainWindow : public QMainWindow {
public:
    MainWindow();
    QGraphicsScene* scene;
private:

};