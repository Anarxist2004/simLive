#include "stdafx.h"
#include "MainApp.h"
#include <QObject>
#include "Food.h"
#include "Animal.h"

MainApp::MainApp()
{
	timer = new QTimer();
	window.scene->addItem(new Animal());
	
	// Подключаем сигнал таймера к слоту, который будет вызывать нужную функцию
	connect(timer, &QTimer::timeout, this, &MainApp::performPeriodicTask);
	timer->start(1000);

	window.resize(1200, 800);
	window.show();

	Quadtree::Rectangle boundary(-100.0f, -100.0f, 100.0f, 100.0f);
	quadTree = new Quadtree(boundary, 4);
	

}

MainApp::~MainApp() {
	delete timer;  // Удаляем таймер
}

void MainApp::performPeriodicTask() {
	for (int i = 0; i < 10; i++) {
		Food* food = new Food();
		window.scene->addItem(food);
		quadTree->insert(food);
	}
	std::vector <Entity*> foundEntities;
	quadTree->queryRange(BaseTools::Point2d(0,0), 40, foundEntities);

	for (Entity*& e : foundEntities) {
		e->setColor(Qt::blue);
		//delete q;
	}
	window.scene->update();
}


