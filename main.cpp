/*************************************************************************
    > File Name: main.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-09 22:54:51
************************************************************************/

#include "mainscene.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainScene mainscene;
    mainscene.show();
    return application.exec();
}
