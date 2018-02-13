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
	void signalLinesRadioButtonToogled(bool);
	void signalElipsRadioButtonToogled(bool);
	void signalQuaderRadioButtonToogled(bool);
	void signalTestRadioButtonToogled(bool);
	void signalSliderRotationChanched(int);
	void signalSliderRotationAbstandChanched(int);
	void signalPointsCheckBoxToogled(bool);


  public slots:
	void SlotSliderChanchedValue(int);
	void SlotSliderDickeChanchedValue(int);
	void SlotOpenSettingsWindow();
	void toggleElipsRadioButton(bool);
	void toggleLinesRadioButton(bool);
	void toggleQuaderRadioButton(bool);
	void toggleTestRadioButton(bool);
	void SlotSliderRotationChanchedValue(int);
	void SlotSliderRotationAbstandChanchedValue(int);
	void SlotPointsCheckBoxChanched(bool);
};

#endif // EVENTHANDLER_H
