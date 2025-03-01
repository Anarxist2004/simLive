#include "stdafx.h"
#include <QtWidgets/QApplication>


#include "MainApp.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainApp MainApp;

    return app.exec();
}
