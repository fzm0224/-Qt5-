#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

#include "choosegrade.h"
#include "about.h"
#include "help.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *b_start;
    QPushButton *b_help;
    QPushButton *b_about;
    QPushButton *b_close;

    QPoint p;

private:
    choosegrade choose_w;
    Help *help;
    About *about;
};

#endif // WIDGET_H
