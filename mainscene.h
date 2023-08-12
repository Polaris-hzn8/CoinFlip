/*************************************************************************
    > File Name: mainscene.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-09 22:54:58
************************************************************************/

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "levelscene.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow {
    Q_OBJECT
public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void paintEvent(QPaintEvent *event);//绘制背景图片
private:
    Ui::MainScene *ui;
    LevelScene *_levelScene = nullptr;
};

#endif // MAINSCENE_H
