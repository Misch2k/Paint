#include "eventhandler.h"
#include <QDebug>

EventHandler::EventHandler(QObject *parent) : QObject(parent) {
}

//Empfange Daten von paintsettings
void EventHandler::SlotSliderChanchedValue(int v) {
	qDebug() << "Eventhandler Slider " << v;
	//Löse Signal aus und Sende Daten mit
	emit signalSliderChanched(v);
}

void EventHandler::SlotSliderDickeChanchedValue(int v) {
	qDebug() << "Eventhandler SliderDicke " << v;
	emit signalSliderDickeChanched(v);
}

void EventHandler::SlotOpenSettingsWindow() {
	emit signalOpenSettings();
}

void EventHandler::toggleElipsRadioButton(bool v) {
	qDebug() << "Elips Radiobutton tooglet ";
	emit signalElipsRadioButtonToogled(v);
}

void EventHandler::toggleLinesRadioButton(bool v) {
	qDebug() << "Lines Radiobutton tooglet ";
	emit signalLinesRadioButtonToogled(v);
}
void EventHandler::toggleQuaderRadioButton(bool v) {
	qDebug() << "Quader Radiobutton tooglet ";
	emit signalQuaderRadioButtonToogled(v);
}
void EventHandler::toggleTestRadioButton(bool v) {
	qDebug() << "Test Radiobutton tooglet ";
	emit signalTestRadioButtonToogled(v);
}
void EventHandler::SlotSliderRotationChanchedValue(int v) {
	qDebug() << "Eventhandler SliderRotation " << v;
	emit signalSliderRotationChanched(v);
}
void EventHandler::SlotSliderRotationAbstandChanchedValue(int v) {
	qDebug() << "Eventhandler SliderRotationAbstand " << v;
	emit signalSliderRotationAbstandChanched(v);
}

