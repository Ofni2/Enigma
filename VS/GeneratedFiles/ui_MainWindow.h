/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGroupBox *input_text_box;
    QPlainTextEdit *Input_text;
    QGroupBox *output_text_box;
    QTextBrowser *Output_text;
    QPushButton *RUN_pushButton;
    QGroupBox *machine_box;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QComboBox *Reflector;
    QComboBox *Rotor_2_Postion;
    QLabel *label_6;
    QComboBox *Rotor_1_Setting;
    QComboBox *Rotor_3_Postion;
    QLabel *label_7;
    QComboBox *Rotor_3_Setting;
    QComboBox *Rotor_2_Setting;
    QComboBox *Rotor_1_Postion;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *Rotor_3_Name;
    QComboBox *Rotor_2_Name;
    QComboBox *Rotor_1_Name;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *Machine;
    QMenuBar *menuBar;
    QMenu *menuRUN;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1095, 532);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        input_text_box = new QGroupBox(centralWidget);
        input_text_box->setObjectName(QStringLiteral("input_text_box"));
        input_text_box->setGeometry(QRect(400, 20, 300, 441));
        Input_text = new QPlainTextEdit(input_text_box);
        Input_text->setObjectName(QStringLiteral("Input_text"));
        Input_text->setGeometry(QRect(10, 30, 281, 401));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(12);
        Input_text->setFont(font);
        Input_text->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        output_text_box = new QGroupBox(centralWidget);
        output_text_box->setObjectName(QStringLiteral("output_text_box"));
        output_text_box->setGeometry(QRect(750, 20, 300, 441));
        Output_text = new QTextBrowser(output_text_box);
        Output_text->setObjectName(QStringLiteral("Output_text"));
        Output_text->setGeometry(QRect(10, 30, 281, 401));
        RUN_pushButton = new QPushButton(centralWidget);
        RUN_pushButton->setObjectName(QStringLiteral("RUN_pushButton"));
        RUN_pushButton->setGeometry(QRect(110, 360, 111, 71));
        machine_box = new QGroupBox(centralWidget);
        machine_box->setObjectName(QStringLiteral("machine_box"));
        machine_box->setGeometry(QRect(30, 20, 351, 301));
        gridLayoutWidget = new QWidget(machine_box);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 331, 231));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Reflector = new QComboBox(gridLayoutWidget);
        Reflector->setObjectName(QStringLiteral("Reflector"));

        gridLayout_2->addWidget(Reflector, 6, 1, 1, 3);

        Rotor_2_Postion = new QComboBox(gridLayoutWidget);
        Rotor_2_Postion->setObjectName(QStringLiteral("Rotor_2_Postion"));

        gridLayout_2->addWidget(Rotor_2_Postion, 4, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        Rotor_1_Setting = new QComboBox(gridLayoutWidget);
        Rotor_1_Setting->setObjectName(QStringLiteral("Rotor_1_Setting"));

        gridLayout_2->addWidget(Rotor_1_Setting, 3, 3, 1, 1);

        Rotor_3_Postion = new QComboBox(gridLayoutWidget);
        Rotor_3_Postion->setObjectName(QStringLiteral("Rotor_3_Postion"));

        gridLayout_2->addWidget(Rotor_3_Postion, 4, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        Rotor_3_Setting = new QComboBox(gridLayoutWidget);
        Rotor_3_Setting->setObjectName(QStringLiteral("Rotor_3_Setting"));

        gridLayout_2->addWidget(Rotor_3_Setting, 3, 1, 1, 1);

        Rotor_2_Setting = new QComboBox(gridLayoutWidget);
        Rotor_2_Setting->setObjectName(QStringLiteral("Rotor_2_Setting"));

        gridLayout_2->addWidget(Rotor_2_Setting, 3, 2, 1, 1);

        Rotor_1_Postion = new QComboBox(gridLayoutWidget);
        Rotor_1_Postion->setObjectName(QStringLiteral("Rotor_1_Postion"));

        gridLayout_2->addWidget(Rotor_1_Postion, 4, 3, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 6, 0, 1, 1);

        Rotor_3_Name = new QComboBox(gridLayoutWidget);
        Rotor_3_Name->setObjectName(QStringLiteral("Rotor_3_Name"));

        gridLayout_2->addWidget(Rotor_3_Name, 2, 1, 1, 1);

        Rotor_2_Name = new QComboBox(gridLayoutWidget);
        Rotor_2_Name->setObjectName(QStringLiteral("Rotor_2_Name"));

        gridLayout_2->addWidget(Rotor_2_Name, 2, 2, 1, 1);

        Rotor_1_Name = new QComboBox(gridLayoutWidget);
        Rotor_1_Name->setObjectName(QStringLiteral("Rotor_1_Name"));

        gridLayout_2->addWidget(Rotor_1_Name, 2, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 4);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 5, 0, 1, 4);

        Machine = new QComboBox(gridLayoutWidget);
        Machine->setObjectName(QStringLiteral("Machine"));

        gridLayout_2->addWidget(Machine, 0, 1, 1, 3);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1095, 26));
        menuRUN = new QMenu(menuBar);
        menuRUN->setObjectName(QStringLiteral("menuRUN"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        QWidget::setTabOrder(Output_text, RUN_pushButton);
        QWidget::setTabOrder(RUN_pushButton, Machine);
        QWidget::setTabOrder(Machine, Rotor_3_Name);
        QWidget::setTabOrder(Rotor_3_Name, Rotor_2_Postion);
        QWidget::setTabOrder(Rotor_2_Postion, Rotor_1_Setting);
        QWidget::setTabOrder(Rotor_1_Setting, Rotor_3_Postion);
        QWidget::setTabOrder(Rotor_3_Postion, Rotor_3_Setting);
        QWidget::setTabOrder(Rotor_3_Setting, Rotor_2_Setting);
        QWidget::setTabOrder(Rotor_2_Setting, Rotor_1_Postion);
        QWidget::setTabOrder(Rotor_1_Postion, Reflector);
        QWidget::setTabOrder(Reflector, Rotor_2_Name);
        QWidget::setTabOrder(Rotor_2_Name, Rotor_1_Name);
        QWidget::setTabOrder(Rotor_1_Name, Input_text);

        menuBar->addAction(menuRUN->menuAction());

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        input_text_box->setTitle(QApplication::translate("MainWindowClass", "Input text", Q_NULLPTR));
        Input_text->setPlainText(QApplication::translate("MainWindowClass", "QBLTW LDAHH YEOEF PTWYB\n"
"LENDP MKOXL DFAMU DWIJD\n"
"XRJZ", Q_NULLPTR));
        output_text_box->setTitle(QApplication::translate("MainWindowClass", "Output text", Q_NULLPTR));
        RUN_pushButton->setText(QApplication::translate("MainWindowClass", "RUN", Q_NULLPTR));
        machine_box->setTitle(QApplication::translate("MainWindowClass", "Machine", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindowClass", "Rotor name", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindowClass", "Start position", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindowClass", "Ring setting", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindowClass", "Reflector", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindowClass", "Machine", Q_NULLPTR));
        menuRUN->setTitle(QApplication::translate("MainWindowClass", "&Fichiers", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
