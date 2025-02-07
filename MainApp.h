#pragma once
#include "MainWindow.h"
#include "Entity.h"

#include <QObject>
#include <QDebug>
#include <QTimer>

#include "BaseTools.h"
#include "Quadtree.h"
class MainApp : public QObject {
	Q_OBJECT
public:
	MainApp();
	~MainApp();
private:
	MainWindow window;
	QTimer* timer;

	Quadtree* quadTree=nullptr;
private slots:
	void performPeriodicTask();
};