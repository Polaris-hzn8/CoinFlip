/*************************************************************************
    > File Name: gamescene.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-12 10:12:38
************************************************************************/

#include "gamescene.h"
#include "mypushbutton.h"
#include "coin.h"
#include <QDebug>
#include <QLabel>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QColor>
#include <QPalette>

//GameScene::GameScene(QWidget *parent) : QMainWindow(parent) {}

GameScene::GameScene(int levelNum) {
    qDebug() << "debug: player entered level " << levelNum;
    _levelNum = levelNum;
    //1.加载游戏窗口
    setFixedSize(400, 700);
    setWindowIcon(QIcon(":/res/img/Coin0001.png"));
    QString title = QString("CoinFlip-level-%1").arg(levelNum);
    setWindowTitle(title);
    //显示当前关卡信息
    QLabel *label = new QLabel(this);
    QFont font;
    font.setFamily("方正喵呜简体");
    font.setPointSize(24);
    font.setBold(true);
    label->setFont(font);
    QString dec = QString("level-%1").arg(levelNum);
    label->setText(dec);
    label->setGeometry(50, this->height()-80, 120, 50);
    //2.quit按钮功能实现
    QMenuBar *mbar = menuBar();
    setMenuBar(mbar);
    QMenu *startMenu = mbar->addMenu("start");
    QAction *quitAction = startMenu->addAction("quit");
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
        qDebug() << "debug: player choosed to return to the level page.";
        QTimer::singleShot(200, this, [=](){
            emit this->gameSceneClose();//向levelscene发送信息
        });
    });
    //4.加载核心游戏内容
    //4-1.加载金币的背景
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QPixmap pixmap = QPixmap(":/res/img/BoardNode.png").scaledToWidth(60);
            QLabel *label = new QLabel(this);
            label->setGeometry(0, 0, pixmap.width(), pixmap.height());
            label->setPixmap(pixmap);
            label->move(75 + i*60, 200 + j*60);
            //4-2.在每个金币的背景中创建金币
            Coin *coin = new Coin(this, ":/res/img/Coin0001.png");
            coin->move(75 + i*60 + pixmap.width()*0.1, 200 + j*60 + pixmap.height()*0.1);
        }
    }
}

//绘制背景图片
void GameScene::paintEvent(QPaintEvent *event) {
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
