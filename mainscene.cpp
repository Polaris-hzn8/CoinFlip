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
#include <QTimer>
#include <QSound>//多媒体模块下的音效头文件
#include <QMediaPlayer>
#include <QMediaPlaylist>

QMediaPlayer* MainScene::_musicPlayer = nullptr;

MainScene::MainScene(QWidget *parent):QMainWindow(parent), ui(new Ui::MainScene) {
    ui->setupUi(this);
    //关闭主界面
    connect(ui->actionquit, &QAction::triggered, this, [=](){
        this->close();
    });
    //1.加载主场景 背景与音效资源
    setFixedSize(400, 700);
    setWindowIcon(QIcon(":/res/img/Coin0001.png"));
    setWindowTitle("CoinFlip");
    QSound *clickSound = new QSound(":/res/music/tap.wav", this);

    //使用QMediaPlayer循环播放音乐的setLoopCount方法似乎有版本兼容问题
    _musicPlayer = new QMediaPlayer(this);
    _musicPlayer->setMedia(QUrl("qrc:/res/music/bgm2.mp3"));
    _musicPlayer->play();
    connect(_musicPlayer, &QMediaPlayer::stateChanged, this ,[=](QMediaPlayer::State playerState){
        if (playerState == QMediaPlayer::StoppedState) _musicPlayer->play();
    });

    //2.加载开始按钮
    MyPushButton *startBtn = new MyPushButton(this, ":/res/img/MenuSceneStartButton.png", "");
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.6);
    //为开始按钮添加点击效果 并实现相应功能
    _levelScene = new LevelScene();
    connect(startBtn, &MyPushButton::clicked, this, [=](){
        qDebug() << "debug: player started the game.";
        startBtn->sink();//按钮向下
        startBtn->jump();//按钮向上
        clickSound->play();
        //利用QTimer定时器延迟1秒进入levelScene场景
        QTimer::singleShot(100, this, [=](){
            this->hide();
            _levelScene->setGeometry(this->geometry());
            _levelScene->show();
        });
    });

    //3.开始监听来自levelscene的信号
    connect(_levelScene, &LevelScene::levelSceneClose, this, [=](){
        _levelScene->close();
        this->setGeometry(_levelScene->geometry());
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


