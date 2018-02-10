#include "paintsettings.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QSlider>
#include <QObject>
#include <QLabel>

paintSettings::paintSettings(EventHandler *h,
							 QWidget *parent) : QWidget(parent) {
	slider = new QSlider(Qt::Orientation::Horizontal);
	slider->setTracking(true);
	slider->setMinimum(2);
	slider->setMaximum(400);
	sliderDicke = new QSlider(Qt::Orientation::Horizontal);
	sliderDicke->setTracking(true);
	sliderDicke->setMinimum(1);
	sliderDicke->setMaximum(50);
	//--------------------------------------------------
	QLabel *infoSliderDist = new QLabel("Abstände");
	QLabel *infoSliderDicke = new QLabel("Dicke");
	QLabel *StatusLabel = new
	QLabel("© <a href=\"https://github.com/EvilAcid\"style=\"color: red;\">Achim Grolimund</a> thanks to <a href=\"https://github.com/Misch2k\"style=\"color: red;\">Michel Kugler</a>");
	StatusLabel->setTextFormat(Qt::TextFormat::RichText);
	StatusLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
	StatusLabel->setOpenExternalLinks(true);
	//--------------------------------------------------
	QFrame *line = new QFrame(this);
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	line->setFixedHeight(2);
	line->setStyleSheet("color:white");
	//--------------------------------------------------
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(infoSliderDist, 0, 0, 1, 2);
	layout->addWidget(slider, 0, 2, 1, 2);
	layout->addWidget(infoSliderDicke, 1, 0, 1, 2);
	layout->addWidget(sliderDicke, 1, 2, 1, 2);
	layout->addWidget(line, 2, 0, 1, 4);
	layout->addWidget(StatusLabel, 3, 0, 1, 4);
	//--------------------------------------------------
	setWindowTitle("Settings");
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
}
