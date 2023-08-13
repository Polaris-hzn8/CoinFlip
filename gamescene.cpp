/*************************************************************************
    > File Name: gamescene.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-12 10:12:38
************************************************************************/

#include "gamescene.h"
#include "mypushbutton.h"
#include "coin.h"
#include "dataconfig.h"
#include <QDebug>
#include <QLabel>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QColor>
#include <QPalette>
#include <QTimer>

#include <iostream>
using namespace std;

//GameScene::GameScene(QWidget *parent) : QMainWindow(parent) {}

GameScene::GameScene(int levelNum) {
    qDebug() << "debug: player entered level " << levelNum;
    //1.初始化类成员属性
    _levelNum = levelNum;
    for (int i = 0; i < 36; ++i) _coins[i%6][i/6] = nullptr;
    //2.加载游戏窗口
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
    //3.quit按钮功能实现
    QMenuBar *mbar = menuBar();
    setMenuBar(mbar);
    QMenu *startMenu = mbar->addMenu("start");
    QAction *quitAction = startMenu->addAction("quit");
    connect(quitAction, &QAction::triggered, this, [=](){
        this->close();
    });
    //4.加载返回按钮
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
    //5.加载核心游戏内容
    //5.1加载关卡数据
    DataConfig dataconfig;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            _levelData[i][j] = dataconfig.mData[_levelNum][i][j];
        }
    }
    //5.2根据载入的关卡数据加载金币
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            //（1）加载金币的背景
            QPixmap pixmap = QPixmap(":/res/img/BoardNode.png").scaledToWidth(60);
            QLabel *label = new QLabel(this);
            label->setGeometry(0, 0, pixmap.width(), pixmap.height());
            label->setPixmap(pixmap);
            label->move(75 + i*60, 200 + j*60);
            //（2）在每个金币的背景中创建金币
            QString coinPath;
            int flag = _levelData[i][j];
            if (flag) {
                coinPath = ":/res/img/Coin0001.png";
            } else {
                coinPath = ":/res/img/Coin0008.png";
            }
            Coin *coin = new Coin(i, j, flag, coinPath, this);
            coin->move(75 + i*60 + pixmap.width()*0.1, 200 + j*60 + pixmap.height()*0.1);
            //（3）将创建的金币对象存入二维数组中 以便于后期维护
            _coins[i + 1][j + 1] = coin;
            //5.3监听金币的点击事件 点击金币触发金币翻转（自定义金币翻转规则 crossFlip 十字反转）
            connect(coin, &Coin::clicked, this, [=](){
                if (!coin->_isFlipping) {
                    //（1）玩家所点击的金币翻转
                    coin->flip();
                    updateData(coin);
                    //（2）点击带动造成其他的金币翻转 翻转延时60ms
                    QTimer::singleShot(60, this, [=](){
                        crossFlip(coin);
                        //XCrossFlip(coin);
                        //（3）检测游戏是否胜利/结束
                        if (check()) {
                            qDebug() << "debug: congratulation! level is complete.";
                        } else {
                            qDebug() << "debug: sorry, please give it another try.";
                        }
                    });
                }
            });
        }
    }
    check();//加载场景后的初次检测
}

//其余金币按照十字翻转规则翻转 利用扩大1格范围的数组处理边界问题
void GameScene::crossFlip(Coin *coin) {
    int x = coin->_posx + 1;
    int y = coin->_posy + 1;
    //1.定义的翻转规则
    Coin* up = _coins[x][y + 1];
    Coin* down = _coins[x][y - 1];
    Coin* left = _coins[x - 1][y];
    Coin* right = _coins[x + 1][y];
    //2.翻转并更新二维数组数据
    if (up) {
        up->flip();
        updateData(up);
    }
    if (down) {
        down->flip();
        updateData(down);
    }
    if (left) {
        left->flip();
        updateData(left);
    }
    if (right) {
        right->flip();
        updateData(right);
    }
}

//其余金币按照叉形翻转规则翻转
void GameScene::XCrossFlip(Coin *coin) {
    int x = coin->_posx + 1;
    int y = coin->_posy + 1;
    //1.定义的翻转规则
    Coin* coin1 = _coins[x + 1][y + 1];
    Coin* coin2 = _coins[x + 1][y - 1];
    Coin* coin3 = _coins[x - 1][y - 1];
    Coin* coin4 = _coins[x - 1][y + 1];
    //2.翻转并更新二维数组数据
    if (coin != nullptr) {
        coin->flip();
        updateData(coin);
    }
    if (coin1 != nullptr) {
        coin1->flip();
        updateData(coin1);
    }
    if (coin2 != nullptr) {
        coin2->flip();
        updateData(coin2);
    }
    if (coin3 != nullptr) {
        coin3->flip();
        updateData(coin3);
    }
    if (coin4 != nullptr) {
        coin4->flip();
        updateData(coin4);
    }
}

void GameScene::updateData(Coin *coin) {
    int x = coin->_posx;
    int y = coin->_posy;
    _levelData[x][y] = _levelData[x][y] == 1 ? 0 : 1;
}

bool GameScene::check() {
    _isComplete = true;
    qDebug() << "debug: start checking...";
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (!_coins[i + 1][j + 1]->_isFront) {
            //if (!_levelData[i][j]) {
                _isComplete = false;
                QString str = QString("The coins at positions(%1, %2) have not been flipped to the front side yet.").arg(i).arg(j);
                qDebug() << str;
            }
    return _isComplete;
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

