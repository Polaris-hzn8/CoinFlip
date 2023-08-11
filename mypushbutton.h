/*************************************************************************
    > File Name: mypushbutton.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-11 17:25:36
************************************************************************/

#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class MyPushButton : public QPushButton {
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QWidget *parent = nullptr, QString normalImag = "", QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;
    void sink();
    void jump();
signals:
public slots:
};

#endif // MYPUSHBUTTON_H
