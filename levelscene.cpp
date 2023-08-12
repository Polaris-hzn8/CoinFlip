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
#include <QTimer>
#include <QString>
#include <QLabel>

LevelScene::LevelScene(QWidget *parent):QMainWindow(parent) {
    //1.设置level窗口基本参数
    setFixedSize(400, 700);
    setWindowIcon(QIcon(":/res/img/Coin0001.png"));
    setWindowTitle("CoinFlip-levelchoose");
    QMenuBar *mbar = menuBar();
    setMenuBar(mbar);
    QMenu *startMenu = mbar->addMenu("start");
    QAction *quitAction = startMenu->addAction("quit");
    //2.quit按钮功能实现
    connect(quitAction, &QAction::triggered, this, [=](){
        this->close();
    });
    //3.加载返回按钮
    QString normalImagePath = ":/res/img/BackButton.png";
    QString pressImagePath = ":/res/img/BackButtonSelected.png";
    MyPushButton *backBtn = new MyPushButton(this, normalImagePath, pressImagePath);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    //back按钮功能实现
    connect(backBtn, &MyPushButton::clicked, this, [=](){
        qDebug() << "debug: player choosed to return to the start page.";
        QTimer::singleShot(200, this, [=](){
            emit this->levelSceneClose();//向mainsecene发送信息
        });
    });
    //4.加载关卡选择按钮
    for (int i = 0; i < 20; ++i) {
        //关卡图片
        MyPushButton *levelBtn = new MyPushButton(this, ":/res/img/LevelIcon.png");
        levelBtn->move(60 + i%4 * 70, 200 + i/4 * 70);
        //关卡数字
        QLabel *label = new QLabel(this);
        label->setFixedSize(levelBtn->width(), levelBtn->height());
        label->setText(QString::number(1 + i));
        label->move(60 + i%4 * 70, 200 + i/4 * 70);
        label->setAlignment(Qt::AlignCenter);//label中的数字居中
        label->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标点击穿过label标签
        //监听每个level按钮的点击事件 准备场景跳转
        connect(levelBtn, &QPushButton::clicked, this, [=](){
            QString str = QString("debug: player choosed level %1.").arg(i + 1);
            qDebug() << str;
            levelBtn->sink();
            levelBtn->jump();
            if (_gamescene == nullptr) {
                this->hide();
                _gamescene = new GameScene(i + 1);
                _gamescene->show();
            }
        });
    }
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





