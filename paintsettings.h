#ifndef PAINTSETTINGS_H
#define PAINTSETTINGS_H

#include <QSlider>
#include <QLabel>
#include <QWidget>
#include <QRadioButton>
#include "paintwidget.h"
#include "myhintlabel.h"

class EventHandler;

class paintSettings : public QWidget {
	Q_OBJECT
  public:
	explicit paintSettings(EventHandler *h, QWidget *parent = nullptr);

  private:
	QSlider *slider;
	QSlider *sliderDicke;
	paintWidget *pw;
	MyHintLabel *sliderHint1;
	MyHintLabel *sliderHint2;
	QRadioButton *linesRadioButton;
	QRadioButton *elipsRadioButton;
	QRadioButton *quaderRadioButton;


  signals:
	void sliderMoved();



};

#endif // PAINTSETTINGS_H
