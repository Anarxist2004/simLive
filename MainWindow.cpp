#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);

    // ����� ������ ����������
    QWidget* leftPanel = new QWidget();
    leftPanel->setFixedWidth(200);

    // ����������� ������� ���������
    QGraphicsView* graphicsView = new QGraphicsView(this);
    graphicsView->scale(4, 4);
    graphicsView->setMinimumWidth(800);
    scene = new QGraphicsScene();
    scene->setSceneRect(graphicsView->rect());
    graphicsView->setScene(scene);
    
    int sceneSize = 100;  // ������ ����� (�������)
    scene->setSceneRect(-sceneSize / 2, -sceneSize / 2, sceneSize, sceneSize); // ������ ������� �����

    // ��������� ���������� �� -100 �� 100 � ���������� �����
    float scale = 1;//sceneSize / 200.0f; // ��������������� ��� ��������� �� -100 �� 100

    // ������������� �� -100 �� 100 �� ����
    QRectF rect(-100 * scale, -100 * scale, 200 * scale, 200 * scale);
    // ������������ ������������� �� �����
    QGraphicsRectItem* rectItem = scene->addRect(rect, QPen(Qt::black), QBrush(Qt::transparent));

    // ������ ������ ����������
    QWidget* rightPanel = new QWidget();
    rightPanel->setFixedWidth(200);
    QVBoxLayout* rightLayout = new QVBoxLayout(rightPanel);


    // ��������� ������ � �������� layout
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(graphicsView, 1); // ����������� ������� �������������
    mainLayout->addWidget(rightPanel);
}
 