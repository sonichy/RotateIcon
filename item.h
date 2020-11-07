#ifndef ITEM_H
#define ITEM_H

#include <QFrame>
#include <QLabel>

namespace Ui {
class Item;
}

class Item : public QFrame
{
    Q_OBJECT   

public:
    explicit Item(QPixmap pixmap, QString name, QString comment, QFrame *parent = nullptr);
    ~Item();
    QLabel *label_name, *label_comment;

protected:
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:
    QLabel *label_icon;

};

#endif // ITEM_H