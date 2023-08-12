/*************************************************************************
    > File Name: gamescene.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-12 10:12:46
************************************************************************/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QMainWindow>

class GameScene : public QMainWindow {
    Q_OBJECT
public:
    //explicit GameScene(QWidget *parent = nullptr);
    GameScene(int levelNum);
    void paintEvent(QPaintEvent *event);
signals:
    //自定义信号 用于通知向levelscene通知gamescene的关闭
    void gameSceneClose();
public slots:
private:
    int _levelNum;
};

#endif // GAMESCENE_H
