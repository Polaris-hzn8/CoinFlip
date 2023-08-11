#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QSize>
#include <QRect>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent, QString normalImag, QString pressImg) {
    setParent(parent);
    //初始化成员
    normalImgPath = normalImag;
    pressImgPath = pressImg;
    //开始加载按钮图片
    QPixmap normal_pixmap;
    if (!normal_pixmap.load(normalImag)) {
        qDebug() << normalImag << " 加载图片失败~";
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
    jump->setDuration(800);
    jump->setStartValue(QRect(this->x(), this->y() + 6, this->width(), this->height()));
    jump->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    jump->setEasingCurve(QEasingCurve::OutBounce);
    jump->start();
}


