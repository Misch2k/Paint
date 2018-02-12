#include "myhintlabel.h"
#include <QPainter>
#include <QDebug>


MyHintLabel::MyHintLabel(QWidget *parent, QSlider *pointer) : QLabel(parent)
{
    this->pointer = pointer;
    QObject::connect(this->pointer, SIGNAL(sliderPressed()), this, SLOT(showHint()));
    QObject::connect(this->pointer, SIGNAL(sliderReleased()), this, SLOT(hideHint()));
    QObject::connect(this->pointer, SIGNAL(sliderMoved(int)), this, SLOT(updateHint(int)));
    this->hide();
    this->setText(QString::number(pointer->value()));
    this->setAlignment(Qt::AlignCenter);
    this->setMaximumWidth(30);
    this->minimumSizeHint();
    qDebug() << "Build complete";
}

void MyHintLabel::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setPen(QPen(Qt::gray,2, Qt::SolidLine, Qt::FlatCap));
    paint.drawArc(1,8,10,10,90*16,90*16);
    paint.drawLine(6,8,23,8);
    paint.drawArc(18,8,10,10,0,90*16);
    paint.drawLine(28, 13, 28, 17);
    paint.drawArc(18,12,10,10,270*16,90*16);
    paint.drawLine(23,22,20,22);
    paint.drawLine(20,22, 14, 30);
    paint.drawLine(14, 30, 8, 22);
    paint.drawLine(8, 22, 6, 22);
    paint.drawArc(1,12,10,10,180*16,90*16);
    paint.drawLine(1,18,1,13);
    QLabel::paintEvent(event);
}

void MyHintLabel::showHint()
{
    this->move(pointer->pos().x()-5 + (pointer->width()-15) * ((double)pointer->value() / pointer->maximum()), pointer->pos().y()-30);
    this->show();
}

void MyHintLabel::hideHint()
{
    this->hide();
}

void MyHintLabel::updateHint(int val)
{
    this->setText(QString::number(val));
    this->move(pointer->pos().x()-5 + (pointer->width()-15) * ((double)pointer->value() / pointer->maximum()), pointer->pos().y()-30);
}

