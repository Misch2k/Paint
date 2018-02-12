#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QMainWindow>
#include <QStatusBar>

class EventHandler;

class paintWidget : public QMainWindow {
	Q_OBJECT

  public:
	paintWidget(QWidget *parent = 0);
	~paintWidget();


  private:
	void paintEvent(QPaintEvent *event);
    int distValue = 20;
	int dickeValue = 1;
	EventHandler *h;
	QStatusBar *statusbar;


  public slots:
	void SlotOpenSettingsWindow();
	void SlotSliderChanchedValue(int );
	void SlotSliderDickeChanchedValue(int );

  signals:
	void signalOpenSettingsWindow();




};

#endif // PAINTWIDGET_H
