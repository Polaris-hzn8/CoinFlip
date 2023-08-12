/*************************************************************************
    > File Name: levelscene.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-11 17:26:39
************************************************************************/

#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QMainWindow>

class LevelScene : public QMainWindow {
    Q_OBJECT
public:
    explicit LevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);//绘制背景图片
signals:
    //自定义信号 用于通知向mainscene通知levelsecen的关闭
    void levelSceneClose();
public slots:
};

#endif // LEVELSCENE_H
