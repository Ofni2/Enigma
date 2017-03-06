/********************************************************************************
** Form generated from reading UI file 'Enigma_Gui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENIGMA_GUI_H
#define UI_ENIGMA_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Enigma_GuiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Enigma_GuiClass)
    {
        if (Enigma_GuiClass->objectName().isEmpty())
            Enigma_GuiClass->setObjectName(QStringLiteral("Enigma_GuiClass"));
        Enigma_GuiClass->resize(600, 400);
        menuBar = new QMenuBar(Enigma_GuiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Enigma_GuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Enigma_GuiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Enigma_GuiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Enigma_GuiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Enigma_GuiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Enigma_GuiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Enigma_GuiClass->setStatusBar(statusBar);

        retranslateUi(Enigma_GuiClass);

        QMetaObject::connectSlotsByName(Enigma_GuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *Enigma_GuiClass)
    {
        Enigma_GuiClass->setWindowTitle(QApplication::translate("Enigma_GuiClass", "Enigma_Gui", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Enigma_GuiClass: public Ui_Enigma_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENIGMA_GUI_H
