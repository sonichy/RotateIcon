#ifndef ROTATEICON_H
#define ROTATEICON_H

#include <QWidget>
#include <QTimer>

class RotateIcon : public QWidget
{
    Q_OBJECT
public:
    explicit RotateIcon(QPixmap pixmap, QWidget *parent = nullptr);
    QPixmap pixmap1;

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QTimer *timer, *timer_delay;
    qreal angle = 0, d = 0;

signals:

public slots:


};

#endif // ROTATEICON_H