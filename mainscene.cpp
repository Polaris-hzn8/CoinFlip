/*************************************************************************
    > File Name: mainscene.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-09 22:55:04
************************************************************************/

#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QTimer>

MainScene::MainScene(QWidget *parent):QMainWindow(parent), ui(new Ui::MainScene) {
    ui->setupUi(this);
    //关闭主界面
    connect(ui->actionquit, &QAction::triggered, this, [=](){
        this->close();
    });
    //主场景窗口设置
    setFixedSize(400, 700);
    setWindowIcon(QIcon(":/res/img/Coin0001.png"));
    setWindowTitle("CoinFlip");

    //加载开始按钮
    MyPushButton *startBtn = new MyPushButton(this, ":/res/img/MenuSceneStartButton.png", "");
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.6);
    //为开始按钮添加点击效果 并实现相应功能
    _levelScene = new LevelScene();
    connect(startBtn, &MyPushButton::clicked, this, [=](){
        qDebug() << "debug: player started the game.";
        startBtn->sink();//按钮向下
        startBtn->jump();//按钮向上
        //利用QTimer定时器延迟1秒进入levelScene场景
        QTimer::singleShot(100, this, [=](){
            this->hide();
            _levelScene->show();
        });
    });

    //开始监听来自levelscene的信号
    connect(_levelScene, &LevelScene::levelSceneClose, this, [=](){
        _levelScene->close();
        this->show();
    });
}

//绘制主场景背景图片
void MainScene::paintEvent(QPaintEvent *event) {
    QPainter painter(this);//当前窗口内绘制
    //1.加载背景
    QPixmap bground;
    bground.load(":/res/img/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), bground);
    //2.加载背景装饰性图标
    QPixmap dec1;
    dec1.load(":/res/img/Title.png");
    //dec1 = dec1.scaled(dec1.width()*0.5, dec1.height()*0.5);
    painter.drawPixmap(20, 50, dec1);
}

MainScene::~MainScene() {
    delete ui;
}


