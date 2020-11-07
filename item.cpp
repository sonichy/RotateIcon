#include "item.h"
#include "rotateicon.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

Item::Item(QPixmap pixmap, QString name, QString comment, QFrame *parent) :
    QFrame(parent)
{
    setStyleSheet("QFrame { background-color:#eeeeee; border-radius:20px; }");
    setFixedSize(300,100);
    QHBoxLayout *HBox = new QHBoxLayout;
    RotateIcon *rotateIcon = new RotateIcon(pixmap);
    HBox->addWidget(rotateIcon, Qt::AlignCenter);
    QVBoxLayout *VBox = new QVBoxLayout;
    label_name = new QLabel(name);
    QFont font = this->font();
    font.setPointSize(font.pointSize() + 5);
    label_name->setFont(font);
    VBox->addWidget(label_name, Qt::AlignCenter);
    label_comment = new QLabel(comment);
    VBox->addWidget(label_comment, Qt::AlignCenter);
    HBox->addLayout(VBox);
    setLayout(HBox);
}

Item::~Item()
{

}

void Item::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void Item::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0,0);
    effect->setColor(QColor(0,0,0,255));
    effect->setBlurRadius(20);
    setGraphicsEffect(effect);
}

void Item::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    setGraphicsEffect(nullptr);
}