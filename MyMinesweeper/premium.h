#ifndef PREMIUM_H
#define PREMIUM_H

#include <QWidget>
#include <QPushButton>

class Premium : public QWidget
{
    Q_OBJECT
public:
    explicit Premium(QWidget *parent = 0);
    ~Premium();

private:
    QPushButton *b_restart;
    QPushButton *b_gotoui;

signals:
    void mysignal_pre();
public slots:
};

#endif // PREMIUM_H
