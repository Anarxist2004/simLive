#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);

    // Левая панель управления
    QWidget* leftPanel = new QWidget();
    leftPanel->setFixedWidth(200);

    // Центральная область отрисовки
    QGraphicsView* graphicsView = new QGraphicsView(this);
    graphicsView->scale(4, 4);
    graphicsView->setMinimumWidth(800);
    scene = new QGraphicsScene();
    scene->setSceneRect(graphicsView->rect());
    graphicsView->setScene(scene);
    
    int sceneSize = 100;  // Размер сцены (квадрат)
    scene->setSceneRect(-sceneSize / 2, -sceneSize / 2, sceneSize, sceneSize); // Задаем границы сцены

    // Переводим координаты от -100 до 100 в координаты сцены
    float scale = 1;//sceneSize / 200.0f; // Масштабирование для диапазона от -100 до 100

    // Прямоугольник от -100 до 100 по осям
    QRectF rect(-100 * scale, -100 * scale, 200 * scale, 200 * scale);
    // Отрисовываем прямоугольник на сцене
    QGraphicsRectItem* rectItem = scene->addRect(rect, QPen(Qt::black), QBrush(Qt::transparent));

    // Правая панель управления
    QWidget* rightPanel = new QWidget();
    rightPanel->setFixedWidth(200);
    QVBoxLayout* rightLayout = new QVBoxLayout(rightPanel);


    // Добавляем панели в основной layout
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(graphicsView, 1); // Центральная область растягивается
    mainLayout->addWidget(rightPanel);
}
 