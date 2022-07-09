#ifndef MIDDLE_H
#define MIDDLE_H

#include <QWidget>
#include <QPushButton>

class Middle : public QWidget
{
    Q_OBJECT
public:
    explicit Middle(QWidget *parent = 0);
    ~Middle();
private:
    QPushButton *b_restart;
    QPushButton *b_gotoui;

signals:
    void mysignal_mid();
public slots:
};

#endif // MIDDLE_H
