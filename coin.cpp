/*************************************************************************
    > File Name: coin.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-13 00:07:58
************************************************************************/

#include "coin.h"
#include <QPixmap>
#include <QDebug>

//Coin::Coin(QWidget *parent) : QPushButton(parent) {}

Coin::Coin(QWidget *parent, QString img) {
    setParent(parent);
    QPixmap pixmap;
    if (!pixmap.load(img)) {
        qDebug() << "debug: coin image load failed." << img;
        return;
    }
    setFixedSize(pixmap.width(), pixmap.height());//设置QPushButton的大小
    setStyleSheet("QPushButton{border:0px;}");//设置QPushButton的样式
    setIcon(pixmap);//设置QPushButton的Icon
    setIconSize(QSize(pixmap.width(), pixmap.height()));//设置QPushButton的Icon大小
}



