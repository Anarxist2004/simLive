#include "stdafx.h"
#include "MainApp.h"
#include <QObject>


MainApp::MainApp()
{
	timerAddFood = new QTimer();
	timerMoveAnimals = new QTimer();
	Animal* animal = new Animal(12,4,4);
	animal->setPos(100, 100);
	animal->setRect(Point2d(-100.f, -100.f), Point2d(100.f, 100.f));
	animal->setColor(animal->generateColor());
	animalVec.push_back(animal);
	window.scene->addItem(animal);




	for (int i = 1; i < 10; i++) {
		animalVec.push_back(new Animal(*animal));
		window.scene->addItem(animalVec[i]);
	}
	
	
	// Подключаем сигнал таймера к слоту, который будет вызывать нужную функцию
	connect(timerAddFood, &QTimer::timeout, this, &MainApp::performPeriodicTask);
	timerAddFood->start(1000);

	connect(timerMoveAnimals, &QTimer::timeout, this, &MainApp::tickMoveAnimals);
	timerMoveAnimals->start(100);

	window.resize(1200, 800);
	window.show();

	Quadtree::Rectangle boundary(-100.0f, -100.0f, 100.0f, 100.0f);
	quadTree = new Quadtree(boundary, 4);
	

}

MainApp::~MainApp() {
	delete timerAddFood;  // Удаляем таймер
	delete timerMoveAnimals;
}

void MainApp::tickMoveAnimals()
{
	for (int i = 0; i < animalVec.size(); i++) {
		

		
		if (animalVec[i]->getEnergy() <= 0 ) {
			window.scene->removeItem(animalVec[i]);
			delete animalVec[i];
			animalVec.erase(animalVec.begin() + i);
			i--;
			break;
		}
		else if (animalVec[i]->age() >= 300) {
			window.scene->removeItem(animalVec[i]);
			delete animalVec[i];
			animalVec.erase(animalVec.begin() + i);
			i--;
			break;
		}
		animalVec[i]->moveRandomly();
		if (animalVec[i]->getEnergy() >= 500) {
			Animal* nAnimal = new Animal(*animalVec[i]);
			nAnimal->modifyAttribute(50, 20);
			nAnimal->setColor(nAnimal->generateColor());
			animalVec.push_back(nAnimal);
			window.scene->addItem(nAnimal);
			nAnimal->setEnergy(animalVec[i]->getEnergy() / 2);
			animalVec[i]->setEnergy(animalVec[i]->getEnergy() / 2 - 20);

		}
		

		float x, y;
		animalVec[i]->getPosition(x, y);
		std::vector <Entity*> foundEntities;
		
		quadTree->queryRange(Point2d(x, y), double(animalVec[i]->scope() / 2), foundEntities);

		std::vector <Entity*> EntitiesDie;
			animalVec[i]->chooseTarget(foundEntities, EntitiesDie);

			for (Entity*& e : EntitiesDie) {
				e->setColor(Qt::blue);
				window.scene->removeItem(e);
				quadTree->remove(e);
				delete e;

			}
	}
	for (int i = 0; i < animalVec.size(); i++) {

	}
	//window.scene->update();
}

void MainApp::performPeriodicTask() {
	for (int i = 0; i < 30; i++) {
		Food* food = new Food();
		window.scene->addItem(food);
		quadTree->insert(food);
	}
}


