#include "rotateicon.h"
#include <QDebug>
#include <QPainter>

RotateIcon::RotateIcon(QPixmap pixmap, QWidget *parent) : QWidget(parent)
{
    setFixedSize(90,90);
    pixmap1 = pixmap;    

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]{
        if (d < 50)
            d = d + 0.05;
        angle += d;
        qDebug() << angle << d;
        update();
    });

    timer_delay = new QTimer(this);
    timer_delay->setSingleShot(true);
    connect(timer_delay, &QTimer::timeout, [=]{
        timer->start(10);
    });
}

void RotateIcon::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.translate(width()/2, height()/2);
    painter.rotate(angle);
    painter.translate(-width()/2, -height()/2);
    painter.drawPixmap(rect(), pixmap1);
    QWidget::paintEvent(event);
}

void RotateIcon::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    timer_delay->start(3000);
    QWidget::enterEvent(event);
}

void RotateIcon::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    timer_delay->stop();
    timer->stop();
    angle = 0;
    d = 0;
    update();
    QWidget::leaveEvent(event);
}