#include "premium.h"

Premium::Premium(QWidget *parent) : QWidget(parent)
{
    b_restart = new QPushButton(this);
    b_restart->move(20, 615);
    b_restart->resize(100, 40);
    b_restart->setText("重新开始");
    b_restart->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}"

                             "QPushButton:pressed{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}");

    b_gotoui = new QPushButton(this);
    b_gotoui->move(1000, 615);
    b_gotoui->resize(100, 40);
    b_gotoui->setText("回主界面");
    b_gotoui->setStyleSheet("QPushButton{"
                            "border-image:url(:/new/prefix1/res/a1.png)"
                            "}"

                            "QPushButton:pressed{"
                            "border-image:url(:/new/prefix1/res/a2.png)"
                            "}");

    //重新开始按钮信号处理
//    connect(b_restart, &QPushButton::pressed, this,
//            [=]()
//            {

//            }
//            );

    //回主界面按钮信号处理
    connect(b_gotoui, &QPushButton::pressed, this,
            [=]()
            {
                emit mysignal_pre();
            }
            );
}

Premium::~Premium()
{

}

