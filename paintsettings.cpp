#include "paintsettings.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QSlider>
#include <QObject>

paintSettings::paintSettings(EventHandler *h,
							 QWidget *parent) : QWidget(parent) {
	slider = new QSlider(Qt::Orientation::Horizontal);
	slider->setTracking(true);
	slider->setMinimum(5);
	slider->setMaximum(400);
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(slider);
	setWindowTitle("Settings");
	setFixedSize(200, 40);
	setWindowFlags(Qt::WindowStaysOnTopHint);
	setLayout(layout);
	//--------------------------------------------------
	//--------------------------------------------------
	//--------------------------------------------------
	//Slider Valuechanched sende Daten an EventHandler
	QObject::connect(this->slider, SIGNAL(valueChanged(int)), h,
					 SLOT(SlotSliderChanchedValue(int)));
}
