#include "paintsettings.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QObject>
#include <QDebug>

paintSettings::paintSettings(EventHandler *h, QWidget *parent) : QWidget(parent) {
	slider = new QSlider(Qt::Orientation::Horizontal);
	slider->setTracking(true);
    slider->setMinimum(1);
    slider->setSliderPosition(20);
    slider->setMaximum(999);

	sliderDicke = new QSlider(Qt::Orientation::Horizontal);
	sliderDicke->setTracking(true);
	sliderDicke->setMinimum(1);
	sliderDicke->setMaximum(50);
    setFixedSize(250, 100);

    sliderHint1 = new MyHintLabel(this, slider);
    sliderHint2 = new MyHintLabel(this, sliderDicke);

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
    layout->setRowStretch(0,5);
    layout->addWidget(infoSliderDist, 1, 0, 1, 2);
    layout->addWidget(slider, 1, 2, 1, 2);
    layout->addWidget(infoSliderDicke, 2, 0, 1, 2);
    layout->addWidget(sliderDicke, 2, 2, 1, 2);
    layout->addWidget(line, 3, 0, 1, 4);
    layout->addWidget(StatusLabel, 4, 0, 1, 4);
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
    //--------------------------------------------------

    sliderHint2->raise();

}
