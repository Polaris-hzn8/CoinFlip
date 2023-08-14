/*************************************************************************
    > File Name: coin.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-13 00:08:04
************************************************************************/

#ifndef COIN_H
#define COIN_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QMouseEvent>
#include <QSound>

class Coin : public QPushButton {
    Q_OBJECT
public:
    //explicit Coin(QWidget *parent = nullptr);
    Coin(int posx, int posy, bool flag, QString img = "", QWidget *parent = nullptr);
    //重写鼠标点击事件处理方法
    void mousePressEvent(QMouseEvent *e);
    void flip();
    int _posx;
    int _posy;
    bool _isFront;//是否为正面
    bool _isFlipping = false;//是否为翻转状态
    bool _isDisabled = false;//是否为禁用状态
private:
    //用于实现金币翻转的参数
    QTimer *_frontTimer;//正面反转定时器
    QTimer *_backTimer;//反面反转定时器
    int _min = 1;
    int _max = 8;
signals:
public slots:
};

#endif // COIN_H
