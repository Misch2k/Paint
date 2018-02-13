#include "paintwidget.h"
#include "paintsettings.h"
#include "eventhandler.h"

#include <QDebug>
#include <QPainter>
#include <QObject>


paintWidget::paintWidget(QWidget *parent)
	: QMainWindow(parent) {
	h = new EventHandler();
	setWindowIcon(QIcon(":/icons/paint.ico"));
	setMinimumHeight(500);
	setMinimumWidth(500);
	QObject::connect(this, SIGNAL(signalOpenSettingsWindow()), h,
					 SLOT(SlotOpenSettingsWindow()));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalOpenSettings()),
					 this, SLOT(SlotOpenSettingsWindow()));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalSliderChanched(int)),
					 this, SLOT(SlotSliderChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalSliderDickeChanched(int)),
					 this, SLOT(SlotSliderDickeChanchedValue(int)));
	//--------------------------------------------------
	emit signalOpenSettingsWindow();
}

paintWidget::~paintWidget() {
}

void paintWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);;
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(QPen(Qt::white, dickeValue * 0.1));
	// Dreieck rechts oben
	for (int i = 0; i <= distValue ; i++) {
		painter.drawLine(0, 0, width(), height() * i / distValue);
	}
	// Dreieck links oben
	for (int i = 0; i < distValue ; i++) {
		painter.drawLine(0, 0, width() * i / distValue, height());
	}
	// Dreieck rechts unten
	for (int i = 0; i < distValue ; i++) {
		painter.drawLine(0, height() * i / distValue, width(), height());
	}
	// Dreieck links unten
	for (int i = 1; i <= distValue ; i++) {
		painter.drawLine(width() * i / distValue, 0, width(), height());
	}
}

void paintWidget::SlotOpenSettingsWindow() {
	qDebug() << "SlotopenSettingWindow ausgelöst";
	paintSettings *ps = new paintSettings(h);
	ps->show();
}

void paintWidget::SlotSliderChanchedValue(int v) {
	qDebug() << "Paint: Slider Wert geändert -> " << v;
	distValue = v;
	paintWidget::repaint();
}

void paintWidget::SlotSliderDickeChanchedValue(int v) {
	dickeValue = v;
	paintWidget::repaint();
}


