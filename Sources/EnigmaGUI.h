#pragma once

#include <QtWidgets>
#include <QApplication>
#include "Enigma.hpp"

class EnigmaGUI :public QMainWindow
{
	//Q_OBJECT

	public:
		EnigmaGUI();

		~EnigmaGUI();
	
	//private slots:
		//void run();

	private:

		QMainWindow *GUI;
		QWidget *centralWidget;

		QGroupBox *input_text_box;
		QPlainTextEdit *Input_text;

		QGroupBox *output_text_box;
		QTextBrowser *Output_text;
		
		QWidget *gridLayoutWidget;
		QGridLayout *configLayout;
		
		QGroupBox *machine_box;

		QComboBox *machine;
		
		QComboBox *Rotor_1_Name;
		QComboBox *Rotor_2_Name;
		QComboBox *Rotor_3_Name;

		QComboBox *Rotor_1_Setting;
		QComboBox *Rotor_2_Setting;
		QComboBox *Rotor_3_Setting;

		QComboBox *Rotor_1_Position;
		QComboBox *Rotor_2_Position;
		QComboBox *Rotor_3_Position;
		
		QComboBox *reflector;
		
		QPushButton *RUN_pushButton;
		
		QLabel *label_machineName;
		QLabel *label_rotorName;
		QLabel *label_rotorPosition;
		QLabel *label_rotorSetting;
		QLabel *label_reflectorName;
		

		QSpacerItem *horizontalSpacer_3;
		QSpacerItem *horizontalSpacer_4;
		
		QMenuBar *menuBar;
		QMenu *menuRUN;
		QToolBar *mainToolBar;
		QStatusBar *statusBar;

};

