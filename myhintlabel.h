#ifndef MYHINTLABEL_H
#define MYHINTLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPaintEvent>

class MyHintLabel : public QLabel
{
    Q_OBJECT
public:
    MyHintLabel(QWidget *parent = Q_NULLPTR, QSlider *pointer = Q_NULLPTR);
protected:
    void paintEvent(QPaintEvent *event);
private:
    QSlider *pointer;
public slots:
  void showHint();
  void hideHint();
  void updateHint(int val);
};

#endif // MYHINTLABEL_H
