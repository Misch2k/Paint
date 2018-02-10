#ifndef PAINTSETTINGS_H
#define PAINTSETTINGS_H

#include <QSlider>
#include <QWidget>
#include "paintwidget.h"

class paintSettings : public QWidget {
	Q_OBJECT
  public:
	explicit paintSettings(QWidget *parent = nullptr);

  private:
	QSlider *slider;
	paintWidget *pw;
  public slots:
  signals:
	void sliderMoved();



};

#endif // PAINTSETTINGS_H
