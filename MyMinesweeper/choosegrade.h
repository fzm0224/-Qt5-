#ifndef CHOOSEGRADE_H
#define CHOOSEGRADE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include "primary.h"
#include "middle.h"
#include "premium.h"

class choosegrade : public QWidget
{
    Q_OBJECT
public:
    explicit choosegrade(QWidget *parent = 0);
    ~choosegrade();

private:
    QPushButton *b_primary;
    QPushButton *b_middle;
    QPushButton *b_premium;

    QLabel *label;
    QPoint point;

private:
    Primary primary_w;
    Middle middle_w;
    Premium premium_w;

signals:
    void mysignal();

public slots:
};

#endif // CHOOSEGRADE_H
