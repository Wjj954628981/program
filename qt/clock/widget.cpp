#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QColorDialog>
#include <QFontDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QTimer *timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(update()));
       timer->start(1000);

       setWindowTitle(tr("Analog Clock"));
       resize(200, 200);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -50)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    static const QPoint secondHand[3] = {
        QPoint(3, 4),
        QPoint(-3, 4),
        QPoint(0, -80)
    };
    int side = qMin(width(), height());
    QTime time = QTime::currentTime();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();
    painter.setPen(hourColor);

    for (int i = 1; i < 13; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.drawText(-6,-75,QString::number((i+10)%12+1));
        painter.rotate(30.0);
    }
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    painter.setPen(minuteColor);
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
    painter.setPen(secondColor);

    for (int k = 0; k < 60; ++k) {
        painter.rotate(6.0);
    }
}



void Widget::on_pushButton_clicked()
{
    hourColor=QColorDialog::getColor(Qt::red,this,tr("颜色对话框"));
}

void Widget::on_pushButton_2_clicked()
{
    minuteColor=QColorDialog::getColor(Qt::red,this,tr("颜色对话框"));
}

void Widget::on_pushButton_3_clicked()
{
    secondColor=QColorDialog::getColor(Qt::red,this,tr("颜色对话框"));
}

void Widget::on_pushButton_4_clicked()
{
    bool ok;
    font=QFontDialog::getFont(&ok,this);
}
