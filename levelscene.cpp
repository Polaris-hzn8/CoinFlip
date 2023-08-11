/*************************************************************************
    > File Name: levelscene.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-11 17:26:25
************************************************************************/

#include "levelscene.h"
#include "mypushbutton.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QDebug>

LevelScene::LevelScene(QWidget *parent):QMainWindow(parent) {
    //设置level窗口基本参数
    setFixedSize(400, 700);
    setWindowIcon(QIcon(":/res/img/Coin0001.png"));
    setWindowTitle("CoinFlip-levelchoose");
    QMenuBar *mbar = menuBar();
    setMenuBar(mbar);
    QMenu *startMenu = mbar->addMenu("start");
    QAction *quitAction = startMenu->addAction("quit");
    //quit按钮功能实现
    connect(quitAction, &QAction::triggered, this, [=](){
        this->close();
    });
    //加载返回按钮
    QString normalImagePath = ":/res/img/BackButton.png";
    QString pressImagePath = ":/res/img/BackButtonSelected.png";
    MyPushButton *backBtn = new MyPushButton(this, normalImagePath, pressImagePath);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    //back按钮功能实现
    connect(backBtn, &MyPushButton::clicked, this, [=](){
        qDebug() << "debug: player choosed to return to the start page.";
    });
}

//绘制背景图片
void LevelScene::paintEvent(QPaintEvent *event) {
    QPainter painter(this);//当前窗口内绘制
    //1.加载背景
    QPixmap bground;
    bground.load(":/res/img/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), bground);
    //2.加载背景装饰性图标
    QPixmap dec1;
    dec1.load(":/res/img/Title.png");
    painter.drawPixmap(20, 50, dec1);
}





