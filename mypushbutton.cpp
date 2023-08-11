#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QSize>

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
