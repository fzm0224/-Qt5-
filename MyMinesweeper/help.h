#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class Help : public QDialog
{
    Q_OBJECT
public:
    explicit Help(QWidget *parent = 0);
    ~Help();

private:
    QLabel *label_title;
    QLabel *label_cont;

    QPushButton *button;

signals:

public slots:
};
#endif // HELP_H
