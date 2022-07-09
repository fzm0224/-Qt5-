#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setFixedSize(600, 400);
    w.setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/res/ui.jpg");
    palette.setBrush(QPalette::Background, QBrush(pixmap.scaled(w.size(),
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation)));
    w.setPalette(palette);

    w.show();

    return a.exec();
}
