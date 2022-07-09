#ifndef PRIMARY_H
#define PRIMARY_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

#define LINE 9
#define NUM 81
#define MINE_NUM 10

class Primary : public QWidget
{
    Q_OBJECT
public:
    explicit Primary(QWidget *parent = 0);
    ~Primary(); 
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* event);
    void initMine();
    void dfs(int x, int y);

private:
    int x;
    int y;
    int num;

private:
    QPushButton *b_restart;
    QPushButton *b_gotoui;
    QPushButton *button[LINE][LINE];

private:
    int map[LINE][LINE];    //地图
    int mark[LINE][LINE];   //标记为初始值得网格和其周围的网格
    int sum[LINE][LINE];    //判断非雷方格点开的数量，用于判断是否胜利
    int flag[LINE][LINE];   //红旗标记

    static int dx[8];   //8方向位移数组
    static int dy[8];

signals:
    void mysignal_pri();
public slots:
};

#endif // PRIMARY_H
