/*************************************************************************
    > File Name: mypushbutton.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-11 17:26:13
************************************************************************/

#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QSize>
#include <QRect>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent, QString normalImg, QString pressImg) {
    setParent(parent);
    //初始化成员
    _normalImgPath = normalImg;
    _pressImgPath = pressImg;
    //开始加载按钮图片
    QPixmap normal_pixmap;
    if (!normal_pixmap.load(_normalImgPath)) {
        qDebug() << "debug: MyPushButton加载图片失败~" << _normalImgPath;
        return;
    }
    this->setFixedSize(normal_pixmap.width(), normal_pixmap.height());
    this->setStyleSheet("QPushButton{border:0px}");//将图片边框设置为0 css语法
    this->setIcon(normal_pixmap);
    this->setIconSize(QSize(normal_pixmap.width(), normal_pixmap.height()));
}

void MyPushButton::sink() {
    //创建动画对象 geometry使用矩形框的范围实现特效
    QPropertyAnimation *sink = new QPropertyAnimation(this, "geometry");
    //设置时间间隔（ms）
    sink->setDuration(300);
    //创建起始位置
    sink->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //创建结束位置
    sink->setEndValue(QRect(this->x(), this->y() + 6, this->width(), this->height()));
    //设置缓和曲线 QEasingCurve::OutBounce为弹跳效果
    sink->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    sink->start();
}

void MyPushButton::jump() {
    QPropertyAnimation *jump = new QPropertyAnimation(this, "geometry");
    jump->setDuration(300);
    jump->setStartValue(QRect(this->x(), this->y() + 6, this->width(), this->height()));
    jump->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    jump->setEasingCurve(QEasingCurve::OutBounce);
    jump->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e) {
    if (this->_pressImgPath != "") {
        //重新加载图片（切换图片）
        QPixmap press_pixmap;
        if (!press_pixmap.load(_pressImgPath)) {
            qDebug() << "debug: MyPushButton加载图片失败~" << _pressImgPath;
            return;
        }
        this->setFixedSize(press_pixmap.width(), press_pixmap.height());
        this->setStyleSheet("QPushButton{border:0px}");//将图片边框设置为0 css语法
        this->setIcon(press_pixmap);
        this->setIconSize(QSize(press_pixmap.width(), press_pixmap.height()));
    }
    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e) {
    //重新加载图片（切换图片）
    if (this->_normalImgPath != "") {
        QPixmap normal_pixmap;
        if (!normal_pixmap.load(_normalImgPath)) {
            qDebug() << "debug: MyPushButton加载图片失败~" << _normalImgPath;
            return;
        }
        this->setFixedSize(normal_pixmap.width(), normal_pixmap.height());
        this->setStyleSheet("QPushButton{border:0px}");//将图片边框设置为0 css语法
        this->setIcon(normal_pixmap);
        this->setIconSize(QSize(normal_pixmap.width(), normal_pixmap.height()));
    }
    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}

