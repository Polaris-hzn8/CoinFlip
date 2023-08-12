/*************************************************************************
    > File Name: gamescene.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-12 10:12:38
************************************************************************/

#include "gamescene.h"
#include <QDebug>

//GameScene::GameScene(QWidget *parent) : QMainWindow(parent) {}

GameScene::GameScene(int levelNum) {
    qDebug() << "debug: player entered level " << levelNum;
    _levelNum = levelNum;
}
