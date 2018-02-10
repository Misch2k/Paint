#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class EventHandler : public QObject {
	Q_OBJECT
  public:
	explicit EventHandler(QObject *parent = nullptr);

  signals:
	void signalOpenSettingsWindow();
	void signalOpenSettings();
	void signalSliderChanched(int);
	void signalSliderDickeChanched(int);


  public slots:
	void SlotSliderChanchedValue(int);
	void SlotSliderDickeChanchedValue(int);
	void SlotOpenSettingsWindow();
};

#endif // EVENTHANDLER_H
