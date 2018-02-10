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

void EventHandler::SlotOpenSettingsWindow() {
	emit signalOpenSettings();
}
