#include "primary.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QMessageBox>

//初始化方向数组
int Primary::dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int Primary::dy[8] = { 1, -1, 0, 1, -1, 0, 1, -1 };

Primary::Primary(QWidget *parent) : QWidget(parent)
{
    QFont font;
    font.setPointSize(13);
    font.setFamily("宋体");
    font.setBold(true);

    //注：0 雷周围   -1 初始值  -2 雷的位置

    //设置随机数种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    b_restart = new QPushButton(this);
    b_restart->move(20, 365);
    b_restart->resize(100, 40);
    b_restart->setText("重新开始");
    b_restart->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}"

                             "QPushButton:clicked{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}");

    b_gotoui = new QPushButton(this);
    b_gotoui->move(305, 365);
    b_gotoui->resize(100, 40);
    b_gotoui->setText("回主界面");
    b_gotoui->setStyleSheet("QPushButton{"
                            "border-image:url(:/new/prefix1/res/a1.png)"
                            "}"

                            "QPushButton:clicked{"
                            "border-image:url(:/new/prefix1/res/a2.png)"
                            "}");

    //初始化
    num = 0;
    x = 55;
    y = 35;
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < LINE; j++)
        {
            map[i][j] = -1; //初始化空为-1
            mark[i][j] = 0;
            flag[i][j] = 0;
            sum[i][j] = 0;
            button[i][j] = new QPushButton(this);
            button[i][j]->resize(35, 35);
            button[i][j]->move(x, y);
            button[i][j]->setStyleSheet("QPushButton{"
                                        "background-color:blue"
                                        "}");
            x += 35;
        }
        x = 55;
        y += 35;
    }

    initMine();

    //按钮鼠标左键按下事件处理
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < LINE; j++)
        {
            connect(button[i][j], &QPushButton::pressed, this,
                    [=]()
                    {
                        //踩到雷
                        if (map[i][j] == -2)
                        {
                            /*
                                游戏结束
                            */
                            for (int a = 0; a < LINE; a++)
                            {
                                for (int b = 0; b < LINE; b++)
                                {
                                    if (map[a][b] == -2)
                                    {
                                        button[a][b]->setStyleSheet("QPushButton{"
                                                                    "border-image:url(:/new/prefix1/res/mine.png)"
                                                                    "}");
                                    }
                                }
                            }
                            QMessageBox::warning(this, "游戏结束", "初级难度挑战失败，游戏结束!");
                        }
                        //踩到空位子
                        else if (map[i][j] == -1)
                        {
                            /*
                                踩到空位子，遍历周围所有空位子，并显示
                            */
                            if (!mark[i][j])
                            {
                                dfs(i, j);
                                button[i][j]->setStyleSheet("QPushButton{"
                                                            "border-image:url(:/new/prefix1/res/bbk.png)"
                                                            "}");
                            }

                            //便利所有mark标记为1的方格，将其周围的未标记的方格也标记为1，并更换button图标
                            int xx, yy;
                            for (int a = 0; a < LINE; a++)
                            {
                                for (int b = 0; b < LINE; b++)
                                {
                                    if (mark[a][b] == 1)
                                    {
                                        for (int ii = 0; ii < 8; ii++)
                                        {
                                            xx = a + dx[ii];
                                            yy = b + dy[ii];
                                            if (xx < 0 || yy < 0 || xx >= LINE || yy >= LINE)
                                            {
                                                continue;
                                            }
                                            if (!mark[xx][yy])
                                            {
                                                sum[xx][yy] = 1;
                                                button[xx][yy]->setFont(font);
                                                button[xx][yy]->setText(QString("%1").arg(map[xx][yy]));
                                                button[xx][yy]->setStyleSheet("QPushButton{"
                                                                            "border-image:url(:/new/prefix1/res/bbk.png)"
                                                                            "}");
                                            }
                                        }
                                    }
                                }
                            }

                        }
                        else
                        {
                            sum[i][j] = 1;
                            button[i][j]->setFont(font);
                            button[i][j]->setText(QString("%1").arg(map[i][j]));
                            button[i][j]->setStyleSheet("QPushButton{"
                                                        "border-image:url(:/new/prefix1/res/bbk.png)"
                                                        "}");
                        }

                        num = 0;
                        for (int ii = 0; ii < LINE; ii++)
                        {
                            for (int jj = 0; jj < LINE; jj++)
                            {
                                if (sum[ii][jj] == 1)
                                {
                                    num++;
                                }
                            }
                        }
                        //游戏胜利判断
                        if (num == 71)
                        {
                            QMessageBox::warning(this, "游戏结束", "初级难度挑战成功，you are good!，游戏结束!");
                        }
                    });
        }
    }

    //重新开始按钮信号处理
    connect(b_restart, &QPushButton::pressed, this,
            [=]()
            {

                for (int i = 0; i < LINE; i++)
                {
                    for (int j = 0; j < LINE; j++)
                    {
                        map[i][j] = -1; //初始化空为-1
                        mark[i][j] = 0;
                        flag[i][j] = 0;
                        sum[i][j] = 0;
                        button[i][j]->setText("");
                        button[i][j]->setStyleSheet("QPushButton{"
                                                    "background-color:blue"
                                                    "}");
                    }
                }
                initMine();
            }
            );

    //回主界面按钮信号处理
    connect(b_gotoui, &QPushButton::pressed, this,
            [=]()
            {
                emit mysignal_pri();
            }
            );
}

Primary::~Primary()
{

}

//地雷的初始化
void Primary::initMine()
{
    //随机地雷位置
    for (int i = 0; i < MINE_NUM; i++)
    {
        int tmp = 0;
        int m = 0, n = 0;
        while (1)
        {
            tmp = qrand() % ( NUM-1 );
            m = tmp / LINE;
            n = tmp % LINE;
            if (map[m][n] == -1)
            {
                map[m][n] = -2;  //有雷初始化为-2

//                qDebug() << tmp << "  " << m << "  " << n;
                break;
            }
        }
    }

    //地雷周围位置赋值为0
    int p = 0, q = 0;
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < LINE; j++)
        {
            if (map[i][j] == -2)
            {
                for (int ii = 0; ii < 8; ii++)
                {
                    p = i + dx[ii];
                    q = j + dy[ii];
                    if (map[p][q] != -2 && (p >= 0 && p < 9) && (q >= 0 && q < 9))
                    {
                        map[p][q] = 0;
                    }
                }
            }
        }
    }

    //计算地雷周围的格子它们周围的地雷个数
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < LINE; j++)
        {
            if (map[i][j] == 0)
            {
                for (int ii = 0; ii < 8; ii++)
                {
                    p = i + dx[ii];
                    q = j + dy[ii];

                    if (map[p][q] == -2 && (p >= 0 && p < 9) && (q >= 0 && q < 9))
                    {
                        map[i][j]++;
                    }
                }
            }
        }
    }
}

//深度优先搜索
void Primary::dfs(int x, int y)
{
    int xx = 0, yy = 0;
    if (mark[x][y])
    {
        return ;
    }
    else
    {
        mark[x][y] = 1;
        sum[x][y] = 1;
        for (int i = 0; i < 8; i++)
        {
            xx = x + dx[i];
            yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= LINE || yy >= LINE)
            {
                continue;
            }
            if (!mark[xx][yy] && map[xx][yy] == -1)
            {
                sum[xx][yy] = 1;
                button[xx][yy]->setStyleSheet("QPushButton{"
                                            "border-image:url(:/new/prefix1/res/bbk.png)"
                                            "}");
                dfs(xx, yy);
            }
        }
    }
}

void Primary::paintEvent(QPaintEvent *)
{
    QPainter p(this);   //创建画家，指定窗口为绘图设备

    //背景图
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/res/choose1.jpg"));
}

//在使用样式表伪状态:pressed的情况下，鼠标左键按下事件不起作用
void Primary::mousePressEvent(QMouseEvent* event)
{
    //右击事件
    if (Qt::RightButton == event->button())
    {
//        qDebug() << event->pos();
        int x, y;
        y = (event->pos().x() - 55) / 35;
        x = (event->pos().y() - 35) / 35;
        if (x < 9 && y < 9)
        {
            if (flag[x][y] == 0)
            {
                flag[x][y] = 1;
                button[x][y]->setStyleSheet("QPushButton{"
                                            "border-image:url(:/new/prefix1/res/flag.png)"
                                            "}");
            }
            else if (flag[x][y] == 1)
            {
                flag[x][y] = 0;
                button[x][y]->setStyleSheet("QPushButton{"
                                            "border-image:url(:/new/prefix1/res/blue.png)"
                                            "}");
            }
        }
    }
}
