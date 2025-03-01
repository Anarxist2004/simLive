#pragma once
#include "MainWindow.h"

#include "..\Widgets\geom.h"

#include <QObject>
#include <QDebug>
#include <QTimer>

#include "..\Widgets\Food.h"
#include "..\Widgets\Animal.h"
#include "..\Widgets\Entity.h"

class MainApp : public QObject {
	Q_OBJECT
public:
	MainApp();
	~MainApp();
private:
	MainWindow window;
	QTimer* timerAddFood;
	QTimer* timerMoveAnimals;

	Quadtree* quadTree=nullptr;

	std::vector <Animal*> animalVec;

	void processAnimal(int index);
private slots:
	void performPeriodicTask();
	void tickMoveAnimals();
};