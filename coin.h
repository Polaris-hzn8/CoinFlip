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
    Coin(QWidget *parent = nullptr, QString img = "");
signals:
public slots:
};

#endif // COIN_H
