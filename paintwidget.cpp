#include "paintwidget.h"
#include "paintsettings.h"
#include "eventhandler.h"
#include "math.h"

#include <QDebug>
#include <QPainter>
#include <QObject>

paintWidget::paintWidget(QWidget *parent)
	: QMainWindow(parent) {
	h = new EventHandler();
	setWindowIcon(QIcon(":/icons/paint.ico"));
	setMinimumHeight(500);
	setMinimumWidth(500);
	//--------------------------------------------------
	QObject::connect(this, SIGNAL(signalOpenSettingsWindow()), h,
					 SLOT(slotOpenSettingsWindow()));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalOpenSettings()),
					 this, SLOT(slotOpenSettingsWindow()));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalSliderChanched(int)),
					 this, SLOT(slotSliderChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalSliderDickeChanched(int)),
					 this, SLOT(slotSliderDickeChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalLinesRadioButtonToogled(bool)),
					 this, SLOT(slotLinesRadioButtonChanched(bool)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalElipsRadioButtonToogled(bool)),
					 this, SLOT(slotElipsRadioButtonChanched(bool)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalQuaderRadioButtonToogled(bool)),
					 this, SLOT(slotQuaderRadioButtonChanched(bool)));
    //--------------------------------------------------
    QObject::connect(h, SIGNAL(signalSpiralRadioButtonToogled(bool)),
                     this, SLOT(slotSpiraleRadioButtonChanched(bool)));
    //--------------------------------------------------
    QObject::connect(h, SIGNAL(signalTestRadioButtonToogled(bool)),
                     this, SLOT(slotTestRadioButtonChanched(bool)));
    //--------------------------------------------------
	QObject::connect(h, SIGNAL(signalSliderRotationChanched(int)),
                     this, SLOT(slotSliderRotationChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalSliderRotationAbstandChanched(int)),
					 this, SLOT(slotSliderRotationAbstandChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(h, SIGNAL(signalPointsCheckBoxToogled(bool)),
					 this, SLOT(slotPointsCheckBoxChanched(bool)));
	//--------------------------------------------------
	emit signalOpenSettingsWindow();
}

paintWidget::~paintWidget() {
}

void paintWidget::paintEvent(QPaintEvent *event) {
	//Settings
	//--------------------------------------------------
	QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.setPen(QPen(Qt::white, dickeValue * 0.1));
	//--------------------------------------------------
	//isLines == True
	if (isLines) {
		// Dreieck rechts oben
		for (int i = 0; i <= distValue ; i++) {
			painter.drawLine(0, 0, width(), height() * i / distValue);
		}
		// Dreieck links oben
		for (int i = 0; i < distValue ; i++) {
			painter.drawLine(0, 0, width() * i / distValue, height());
		}
		// Dreieck rechts unten
		for (int i = 0; i < distValue ; i++) {
			painter.drawLine(0, height() * i / distValue, width(), height());
		}
		// Dreieck links unten
		for (int i = 1; i <= distValue ; i++) {
			painter.drawLine(width() * i / distValue, 0, width(), height());
		}
	} else if (isElips) {
		for (int i = 0; i < distValue; i++) {
			painter.drawEllipse(QPointF(width() / 2, height() / 2),
								(width() / 2) * i / distValue, (height() / 2) * i / distValue);
		}
	} else if (isQuader) {
		int breite(0), hoehe(0);
		for (int i = 0; i < distValue; i++) {
			hoehe = (height() ) * i / distValue;
            breite = (width() ) * i / distValue;
            painter.drawRect((width() / 2 ) - (breite / 2), (height() / 2) - (hoehe / 2),
                             breite, hoehe);
        }
	} else if (isTest) {
		//Bringt die Koordinate 0,0 in die Mitte der Fensters
        painter.translate(width() / 2, height() / 2);
        double delta;
        int x, y, r;
        int rot = rotation / 9;
        for (int i = 0; i < distValue; i++) {
            r = (width() ) * i / distValue;
            x=0; y=r;
            delta = 5.0/4.0 - r;
            painter.setPen(QPen(Qt::white, rot < 10 ? (double)rot*0.2+0.5 : ((double)rot -20) * -0.2+0.5));

            while (y>=x) {
                painter.drawPoint(QPoint(0+x,0+y));
                painter.drawPoint(QPoint(0+x,0-y));
                painter.drawPoint(QPoint(0-x,0+y));
                painter.drawPoint(QPoint(0-x,0-y));
                painter.drawPoint(QPoint(0+y,0+x));
                painter.drawPoint(QPoint(0+y,0-x));
                painter.drawPoint(QPoint(0-y,0+x));
                painter.drawPoint(QPoint(0-y,0-x));

                if (delta < 0.0 ) {
                    delta += 2*x + (rotation-70)*3;
                    x++;
                }
                else {
                     delta += 2*x - 2*y + (rotation-70)*3;
                     x++;
                     y--;
                }
            }
        }
        painter.resetTransform();
	} else if (isSpirale) {
		//Bringt die Koordinate 0,0 in die Mitte der Fensters
		painter.translate(width() / 2, height() / 2);
		int x_versatz = versatz;
		if (!isSpirale_Points) {
			for (int var(0); var < distValue; ++var) {
				painter.drawEllipse(QPointF(x_versatz, 0), 50, 50);
				//Rotation um xx Grad
				painter.rotate(rotation);
				x_versatz += versatz;
				qDebug() << "isSpirale Rotation " << rotation;
				qDebug() << "isSpirale Abstand " << versatz;
			}
			painter.resetTransform();
		} else if (isSpirale_Points) {
			for (int var(0); var < distValue; ++var) {
				painter.drawPoint(QPointF(x_versatz, 0));
				//Rotation um xx Grad
				painter.rotate(rotation);
				x_versatz += versatz;
				qDebug() << "isSpirale Rotation " << rotation;
				qDebug() << "isSpirale Abstand " << versatz;
			}
			painter.resetTransform();
		}
	} else {
		painter.drawText(QPoint(width() / 2, height() / 2), "FAIL");
	}
}

//--------------------------------------------------
//Slots
//--------------------------------------------------
void paintWidget::slotOpenSettingsWindow() {
	qDebug() << "SlotopenSettingWindow ausgelöst";
	paintSettings *ps = new paintSettings(h);
	ps->show();
}
void paintWidget::slotSliderChanchedValue(int v) {
	qDebug() << "Paint: Slider Wert geändert -> " << v;
	distValue = v;
	paintWidget::repaint();
}
void paintWidget::slotSliderDickeChanchedValue(int v) {
	dickeValue = v;
	paintWidget::repaint();
}
void paintWidget::slotLinesRadioButtonChanched(bool v) {
	qDebug() << "Paintwidget Lines --> " << v;
	isLines = v;
	paintWidget::repaint();
}
void paintWidget::slotElipsRadioButtonChanched(bool v) {
	qDebug() << "Paintwidget Elips --> " << v;
	isElips = v;
	paintWidget::repaint();
}
void paintWidget::slotQuaderRadioButtonChanched(bool v) {
	qDebug() << "Paintwidget Quader --> " << v;
	isQuader = v;
	paintWidget::repaint();
}
void paintWidget::slotTestRadioButtonChanched(bool v) {
    qDebug() << "Paintwidget Test --> " << v;
    isTest = v;
    paintWidget::repaint();
}
void paintWidget::slotSpiraleRadioButtonChanched(bool v) {
    qDebug() << "Paintwidget Spirale --> " << v;
	isSpirale = v;
	paintWidget::repaint();
}
void paintWidget::slotSliderRotationChanchedValue(int v) {
	qDebug() << "Paint: SliderRotation Wert geändert -> " << v;
	rotation = v;
	paintWidget::repaint();
}
void paintWidget::slotSliderRotationAbstandChanchedValue(int v) {
	qDebug() << "Paint: SliderRotationAbstand Wert geändert -> " << v;
	versatz = v;
	paintWidget::repaint();
}
void paintWidget::slotPointsCheckBoxChanched(bool v) {
	qDebug() << "Paintwidget Points --> " << v;
	isSpirale_Points = v;
	paintWidget::repaint();
}
