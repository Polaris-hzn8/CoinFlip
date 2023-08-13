/*************************************************************************
    > File Name: coin.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-13 00:07:58
************************************************************************/

#include "coin.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>

//Coin::Coin(QWidget *parent) : QPushButton(parent) {}

Coin::Coin(int posx, int posy, bool flag, QString img, QWidget *parent) {
    //1.初始化金币的成员变量
    setParent(parent);
    _posx = posx;
    _posy = posy;
    _isFront = flag;
    _frontTimer = new QTimer(this);
    _backTimer = new QTimer(this);
    QPixmap pixmap;
    if (!pixmap.load(img)) {
        qDebug() << "debug: coin image load failed." << img;
        return;
    }
    setFixedSize(pixmap.width(), pixmap.height());//设置QPushButton的大小
    setStyleSheet("QPushButton{border:0px;}");//设置QPushButton的样式
    setIcon(pixmap);//设置QPushButton的Icon
    setIconSize(QSize(pixmap.width(), pixmap.height()));//设置QPushButton的Icon大小

    //2.监听定时器信号 翻转金币
    connect(_frontTimer, &QTimer::timeout, this, [=](){
        QPixmap pixmap;
        QString imgPath = QString(":/res/img/Coin000%1.png").arg(_min++);
        pixmap.load(imgPath);
        setFixedSize(pixmap.width(), pixmap.height());//设置QPushButton的大小
        setStyleSheet("QPushButton{border:0px;}");//设置QPushButton的样式
        setIcon(pixmap);//设置QPushButton的Icon
        setIconSize(QSize(pixmap.width(), pixmap.height()));//设置QPushButton的Icon大小
        //如果金币反转完成 将定时器停止
        if (_min > _max) {
            _min = 1;
            _frontTimer->stop();
            _isFlipping = false;
        }
    });
    connect(_backTimer, &QTimer::timeout, this, [=](){
        QPixmap pixmap;
        QString imgPath = QString(":/res/img/Coin000%1.png").arg(_max--);
        pixmap.load(imgPath);
        setFixedSize(pixmap.width(), pixmap.height());//设置QPushButton的大小
        setStyleSheet("QPushButton{border:0px;}");//设置QPushButton的样式
        setIcon(pixmap);//设置QPushButton的Icon
        setIconSize(QSize(pixmap.width(), pixmap.height()));//设置QPushButton的Icon大小
        //如果金币反转完成 将定时器停止
        if (_min > _max) {
            _max = 8;
            _backTimer->stop();
            _isFlipping = false;
        }
    });
}

void Coin::flip() {
    _isFlipping = true;
    if (_isFront) {
        _frontTimer->start(30);//每30ms触发一次定时事件
        _isFront = false;
    } else {
        _backTimer->start(30);//每30ms触发一次定时事件
        _isFront = true;
    }
}



