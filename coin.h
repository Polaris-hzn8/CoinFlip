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

class Coin : public QPushButton {
    Q_OBJECT
public:
    //explicit Coin(QWidget *parent = nullptr);
    Coin(int posx, int posy, bool isFront, QString img = "", QWidget *parent = nullptr);
    void flip();
    int _posx;
    int _posy;
    bool _isFront;
    bool _isFlipping = false;
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
