/*************************************************************************
    > File Name: dataconfig.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-13 11:41:32
************************************************************************/

#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QMap>
#include <QObject>
#include <QVector>

class DataConfig : public QObject {
    Q_OBJECT
public:
    explicit DataConfig(QObject* parent = nullptr);
public:
    //关卡id 二维数组存储的关卡数据
    QMap<int, QVector<QVector<int>>> mData;
signals:
public slots:
};

#endif // DATACONFIG_H
