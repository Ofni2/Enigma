#include "EnigmaGUI.h"



EnigmaGUI::EnigmaGUI()
{

	// Groupe : Configuration

	QGroupBox *configBox = new QGroupBox;
	configLayout = new QGridLayout;

	configBox->setTitle("Configuration");
	configBox->setLayout(configLayout);


	QLabel *label_machineName = new QLabel("Machine :");
	machine = new QComboBox;

	QLabel *label_rotorName = new QLabel("Rotor :");
	Rotor_1_Name = new QComboBox;
	Rotor_2_Name = new QComboBox;
	Rotor_3_Name = new QComboBox;

	QLabel *label_rotorSetting = new QLabel("Setting :");
	Rotor_1_Setting = new QComboBox;
	Rotor_2_Setting = new QComboBox;
	Rotor_3_Setting = new QComboBox;

	QLabel *label_rotorPosition = new QLabel("Position :");
	Rotor_1_Position = new QComboBox;
	Rotor_2_Position = new QComboBox;
	Rotor_3_Position = new QComboBox;

	QLabel *label_reflectorName = new QLabel("Reflector :");
	reflector = new QComboBox;
		

	configLayout->addWidget(label_machineName, 0, 0);
	configLayout->addWidget(label_rotorName, 1, 0);
	configLayout->addWidget(label_rotorSetting, 2, 0);
	configLayout->addWidget(label_rotorPosition, 3, 0);
	configLayout->addWidget(label_reflectorName, 4, 0);

	configLayout->addWidget(machine, 0, 1,1,4);

	configLayout->addWidget(Rotor_1_Setting, 1, 1);
	configLayout->addWidget(Rotor_2_Setting, 1, 2);
	configLayout->addWidget(Rotor_3_Setting, 1, 3);

	configLayout->addWidget(Rotor_1_Position, 2, 1);
	configLayout->addWidget(Rotor_2_Position, 2, 2);
	configLayout->addWidget(Rotor_3_Position, 2, 3);

	configLayout->addWidget(Rotor_1_Name, 3, 1);
	configLayout->addWidget(Rotor_2_Name, 3, 2);
	configLayout->addWidget(Rotor_3_Name, 3, 3);

	configLayout->addWidget(reflector, 4, 1,1,4);

	// Groupe : Input text
	QGroupBox *InputBox = new QGroupBox;
	QGridLayout *InputGridLayout = new QGridLayout;

	InputBox->setTitle("Input text");
	Input_text = new QPlainTextEdit(InputBox);
	Input_text->setFont(QFont("Consolas",12));
	Input_text->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
	Input_text->setMinimumSize(QSize(300,200));
	Input_text->setPlainText("QBLTW LDAHH YEOEF PTWYB LENDP MKOXL DFAMU DWIJD XRJZ");
	InputGridLayout->addWidget(Input_text);

	InputBox->setLayout(InputGridLayout);


	// Groupe : Output text
	QGroupBox *OutputBox = new QGroupBox;
	QGridLayout *OutputGridLayout = new QGridLayout;

	OutputBox->setTitle("Output text");
	Output_text = new QTextBrowser;
	Output_text->setFont(QFont("Consolas", 12));
	Output_text->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
	Output_text->setMinimumSize(QSize(300, 200));
	OutputGridLayout->addWidget(Output_text);

	OutputBox->setLayout(OutputGridLayout);


	// Définition du layout principal, du titre de la fenêtre
	centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	QHBoxLayout *MainHLayout = new QHBoxLayout;
	QVBoxLayout *MainVLayout = new QVBoxLayout;
	
	MainHLayout->addWidget(configBox);
	MainHLayout->addWidget(InputBox);
	MainHLayout->addWidget(OutputBox);

	//MainVLayout->addLayout(MainHLayout);
	//MainVLayout->addWidget(RUN_pushButton);


	centralWidget->setLayout(MainHLayout);

	//Definition du layout principal
/*	centralWidget = new QWidget;
	setCentralWidget(centralWidget);

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

	menuBar = new QMenuBar;
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
	*/


}


EnigmaGUI::~EnigmaGUI()
{
}
