#include "paintsettings.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QObject>
#include <QDebug>
#include <QRadioButton>
#include <QGroupBox>
#include <QFormLayout>

paintSettings::paintSettings(EventHandler *h,
							 QWidget *parent) : QWidget(parent) {
	slider = new QSlider(Qt::Orientation::Horizontal);
	slider->setTracking(true);
	slider->setMinimum(1);
	slider->setSliderPosition(20);
	slider->setMaximum(999);
	sliderDicke = new QSlider(Qt::Orientation::Horizontal);
	sliderDicke->setTracking(true);
	sliderDicke->setMinimum(1);
	sliderDicke->setMaximum(50);
	//setFixedSize(250, 100);
	sliderHint1 = new MyHintLabel(this, slider);
	sliderHint2 = new MyHintLabel(this, sliderDicke);
	sliderRotation = new QSlider(Qt::Orientation::Horizontal);
	sliderRotation->setRange(1, 179);
	sliderRotationAbstand = new QSlider(Qt::Orientation::Horizontal);
	sliderRotationAbstand->setRange(1, 200);
	//--------------------------------------------------
	QLabel *StatusLabel = new
	QLabel("© <a href=\"https://github.com/EvilAcid\"style=\"color: red;\">Achim Grolimund</a> thanks to <a href=\"https://github.com/Misch2k\"style=\"color: red;\">Michel Kugler</a>");
	StatusLabel->setTextFormat(Qt::TextFormat::RichText);
	StatusLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
	StatusLabel->setOpenExternalLinks(true);
	//--------------------------------------------------
	linesRadioButton = new QRadioButton();
	linesRadioButton->setChecked(true);
	elipsRadioButton = new QRadioButton();
	quaderRadioButton = new QRadioButton();
	testRadioButton = new QRadioButton();
	//--------------------------------------------------
	QFrame *line = new QFrame(this);
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	line->setFixedHeight(2);
	line->setStyleSheet("color:white");
	//--------------------------------------------------
	QFormLayout *einstellungenFormLayout = new QFormLayout;
	QGroupBox *einstellungenGroupBox = new QGroupBox("Einstellung");
	einstellungenFormLayout->addRow(tr("Anz.Linien"), slider);
	einstellungenFormLayout->addRow(tr("Dicke"), sliderDicke);
	einstellungenGroupBox->setLayout(einstellungenFormLayout);
	//--------------------------------------------------
	QFormLayout *musterFormLayout = new QFormLayout;
	QGroupBox *musterGroupBox = new QGroupBox("Muster");
	musterFormLayout->addRow(tr("Linien"), linesRadioButton);
	musterFormLayout->addRow(tr("Elipse"), elipsRadioButton);
	musterFormLayout->addRow(tr("Quader"), quaderRadioButton);
	musterFormLayout->addRow(tr("Test"), testRadioButton);
	musterFormLayout->addRow(tr("     - Rotation"), sliderRotation);
	musterFormLayout->addRow(tr("     - Abstand"), sliderRotationAbstand);
	musterGroupBox->setLayout(musterFormLayout);
	//--------------------------------------------------
	QGridLayout *layout = new QGridLayout();
	layout->setRowStretch(0, 20);
	layout->addWidget(einstellungenGroupBox, 1, 0, 2, 7);
	layout->addWidget(musterGroupBox, 4, 0, 3, 7);
	//--------------------------------------------------
	//Line, Copyright and Thanks Label
	layout->addWidget(line, 10, 0, 1, 7);
	layout->addWidget(StatusLabel, 11, 0, 1, 7);
	//--------------------------------------------------
	setWindowTitle("Settings");
	setWindowIcon(QIcon(":/icons/settings_1.ico"));
	//setFixedSize(200, 40);
	setWindowFlags(Qt::WindowStaysOnTopHint);
	setLayout(layout);
	//--------------------------------------------------
	//--------------------------------------------------
	//--------------------------------------------------
	//Slider Valuechanched sende Daten an EventHandler
	QObject::connect(this->slider, SIGNAL(valueChanged(int)), h,
					 SLOT(SlotSliderChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(this->sliderDicke, SIGNAL(valueChanged(int)), h,
					 SLOT(SlotSliderDickeChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect( this->linesRadioButton, SIGNAL(toggled(bool)),
					  h, SLOT(toggleLinesRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect( this->elipsRadioButton, SIGNAL(toggled(bool)),
					  h, SLOT(toggleElipsRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect( this->quaderRadioButton, SIGNAL(toggled(bool)),
					  h, SLOT(toggleQuaderRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect( this->testRadioButton, SIGNAL(toggled(bool)),
					  h, SLOT(toggleTestRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect(this->sliderRotation, SIGNAL(valueChanged(int)), h,
					 SLOT(SlotSliderRotationChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(this->sliderRotationAbstand, SIGNAL(valueChanged(int)), h,
					 SLOT(SlotSliderRotationAbstandChanchedValue(int)));
	sliderHint2->raise();
}
