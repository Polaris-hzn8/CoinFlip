/*************************************************************************
    > File Name: main.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-09 22:54:51
************************************************************************/

#include "mainscene.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainScene w;
    w.show();
    return a.exec();
}
