#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置字体
    QFont font;
    font.setPointSize(12);
    font.setFamily("幼圆");
    font.setBold(true);

    b_start = new QPushButton(this);
    b_start->resize(100, 40);
    b_start->move(250, 190);
    b_start->setFont(font);
    b_start->setText("开始游戏");
    b_start->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}");

    b_help = new QPushButton(this);
    b_help->resize(100, 40);
    b_help->move(250, 240);
    b_help->setFont(font);
    b_help->setText("帮助");
    b_help->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}");

    b_about = new QPushButton(this);
    b_about->resize(100, 40);
    b_about->move(250, 290);
    b_about->setFont(font);
    b_about->setText("关于");
    b_about->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}");

    b_close = new QPushButton(this);
    b_close->resize(100, 40);
    b_close->move(250, 340);
    b_close->setFont(font);
    b_close->setText("退出游戏");
    b_close->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}");

    //开始游戏
    connect(b_start, &QPushButton::pressed, this,
            [=]()
            {
                choose_w.show();
                this->hide();
            }
            );

    //帮助
    connect(b_help, &QPushButton::pressed, this,
            [=]()
            {
                help = new Help;
            }
            );

    //关于
    connect(b_about, &QPushButton::pressed, this,
            [=]()
            {
                about = new About;
            }
            );

    //退出游戏
    connect(b_close, &QPushButton::clicked, this,
            [=]()
            {
                exit(0);
            }
            );

    //处理子窗口发来的信号
    connect(&choose_w, &choosegrade::mysignal, this,
            [=]()
            {
                this->show();
                choose_w.hide();
            }
            );
}

Widget::~Widget()
{

}
