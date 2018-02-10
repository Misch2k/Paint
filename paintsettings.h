#ifndef PAINTSETTINGS_H
#define PAINTSETTINGS_H

#include <QSlider>
#include <QWidget>
#include "paintwidget.h"

class EventHandler;

class paintSettings : public QWidget {
	Q_OBJECT
  public:
	explicit paintSettings(EventHandler *h, QWidget *parent = nullptr);

  private:
	QSlider *slider;
	QSlider *sliderDicke;
	paintWidget *pw;
  public slots:
  signals:
	void sliderMoved();



};

#endif // PAINTSETTINGS_H
