#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QMainWindow>

class paintWidget : public QMainWindow {
	Q_OBJECT

  public:
	paintWidget(QWidget *parent = 0);
	~paintWidget();


  private:
	void paintEvent(QPaintEvent *event);
	int distValue;



  public slots:
	void SlotOpenSettingsWindow();
	void SlotSliderChanchedValue(int );

  signals:
	void signalOpenSettingsWindow();




};

#endif // PAINTWIDGET_H
