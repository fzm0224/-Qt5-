#include "help.h"

Help::Help(QWidget *parent) : QDialog(parent)
{
    //固定窗口大小
    this->setFixedSize(500, 320);
    this->setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/res/choose1.jpg");
    palette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(),
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation)));
    this->setPalette(palette);


    label_title = new QLabel(this);
    label_title->resize(160, 40);
    label_title->move(170, 20);
    label_title->setText(QString("<center><h1>游戏规则</h1></center>"));
    label_title->setStyleSheet("QLabel{"
                               "border-image:url(:/new/prefix1/res/title1.jpg)"
                               "}");

    QFont fontlabel;
    fontlabel.setPointSize(13);
    fontlabel.setFamily("幼圆");
    fontlabel.setBold(true);

    label_cont = new QLabel(this);
    label_cont->resize(410, 155);
    label_cont->move(45, 80);
    //自动换行
    label_cont->setWordWrap(true);
    //顶端开始
    label_cont->setAlignment(Qt::AlignTop);
    label_cont->setFont(fontlabel);
    label_cont->setText("    使用鼠标左键随机点击一个方格，方格即被打开并显示出方格中的数字；"
                        "方格中数字则表示其周围的8个方格隐藏了几颗雷；如果点开的格子为空白格，"
                        "即其周围有0颗雷，则其周围格子自动打开；如果其周围还有空白格，则会引发"
                        "连锁反应；在你认为有雷的格子上，点击右键即可标记雷；把所有非地雷的格子"
                        "揭开即胜利；踩到地雷格子就算失败。");

    label_cont->setStyleSheet("QLabel{"
                              "background-color:khaki"
                              "}");

    button = new QPushButton(this);
    button->resize(100, 40);
    button->move(200, 260);
    button->setFont(fontlabel);
    button->setText("退出");
    button->setStyleSheet("QPushButton{"
                          "border-image:url(:/new/prefix1/res/a1.png)"
                          "}"

                          "QPushButton:pressed{"
                          "border-image:url(:/new/prefix1/res/a2.png)"
                          "}");

    connect(button, &QPushButton::pressed, this,
            [=]()
            {
                this->close();
            });

    this->exec();
}

Help::~Help()
{

}

