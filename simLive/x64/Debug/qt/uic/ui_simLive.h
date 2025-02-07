/********************************************************************************
** Form generated from reading UI file 'simLive.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMLIVE_H
#define UI_SIMLIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simLiveClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *simLiveClass)
    {
        if (simLiveClass->objectName().isEmpty())
            simLiveClass->setObjectName(QString::fromUtf8("simLiveClass"));
        simLiveClass->resize(600, 400);
        menuBar = new QMenuBar(simLiveClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        simLiveClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(simLiveClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        simLiveClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(simLiveClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        simLiveClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(simLiveClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        simLiveClass->setStatusBar(statusBar);

        retranslateUi(simLiveClass);

        QMetaObject::connectSlotsByName(simLiveClass);
    } // setupUi

    void retranslateUi(QMainWindow *simLiveClass)
    {
        simLiveClass->setWindowTitle(QCoreApplication::translate("simLiveClass", "simLive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simLiveClass: public Ui_simLiveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMLIVE_H
