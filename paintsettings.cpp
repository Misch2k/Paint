#include "paintsettings.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QSlider>
#include <QObject>

paintSettings::paintSettings(QWidget *parent) : QWidget(parent) {
	slider = new QSlider(Qt::Orientation::Horizontal);
	slider->setTracking(true);
	slider->setMinimum(5);
	slider->setMaximum(200);
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(slider);
	setWindowTitle("Settings");
	setWindowFlags(Qt::WindowStaysOnTopHint);
	setLayout(layout);
	//--------------------------------------------------
	EventHandler *h = new EventHandler();
	//--------------------------------------------------
	//--------------------------------------------------
	//Slider Valuechanched sende Daten an EventHandler
	QObject::connect(this->slider, SIGNAL(valueChanged(int)), h,
					 SLOT(SlotSliderChanchedValue(int)));
}
