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
	bool isLines = 1;
	bool isElips = 0;
	bool isQuader = 0;
	EventHandler *h;
	QStatusBar *statusbar;


  public slots:
	void SlotOpenSettingsWindow();
	void SlotSliderChanchedValue(int );
	void SlotSliderDickeChanchedValue(int );
	void SlotLinesRadioButtonChanched(bool );
	void SlotElipsRadioButtonChanched(bool );
	void SlotQuaderRadioButtonChanched(bool );

  signals:
	void signalOpenSettingsWindow();




};

#endif // PAINTWIDGET_H
