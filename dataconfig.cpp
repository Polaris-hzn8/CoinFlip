/*************************************************************************
    > File Name: dataconfig.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-13 11:41:25
************************************************************************/

#include "dataconfig.h"
#include <QDebug>

DataConfig::DataConfig(QObject* parent):QObject(parent) {
    QVector<QVector<int>> v;
    //=====================================================================level1
    int array1[4][4] = {
        { 1, 1, 1, 1 },
        { 1, 1, 0, 1 },
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array1[i][j]);
        v.push_back(v1);
    }
    mData.insert(1, v);
    v.clear();
    //=====================================================================level2
    int array2[4][4] = {
        { 1, 0, 1, 1 },
        { 0, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 1, 1, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array2[i][j]);
        v.push_back(v1);
    }
    mData.insert(2, v);
    v.clear();
    //=====================================================================level3
    int array3[4][4] = {
        { 0, 0, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) {
            v1.push_back(array3[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(3, v);
    v.clear();
    //=====================================================================level4
    int array4[4][4] = {
        { 0, 1, 1, 1 },
        { 1, 0, 0, 1 },
        { 1, 0, 1, 1 },
        { 1, 1, 1, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array4[i][j]);
        v.push_back(v1);
    }
    mData.insert(4, v);
    v.clear();
    //=====================================================================level5
    int array5[4][4] = {
        { 1, 0, 0, 1 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 0, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) {
            v1.push_back(array5[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(5, v);
    v.clear();
    //=====================================================================level6
    int array6[4][4] = {
        { 1, 0, 0, 1 },
        { 0, 1, 1, 0 },
        { 0, 1, 1, 0 },
        { 1, 0, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) {
            v1.push_back(array6[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(6, v);
    v.clear();
    //=====================================================================level7
    int array7[4][4] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 1 },
        { 1, 1, 1, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array7[i][j]);
        v.push_back(v1);
    }
    mData.insert(7, v);
    v.clear();
    //=====================================================================level8
    int array8[4][4] = {
        { 0, 1, 0, 1 },
        { 1, 0, 0, 0 },
        { 0, 0, 0, 1 },
        { 1, 0, 1, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array8[i][j]);
        v.push_back(v1);
    }
    mData.insert(8, v);
    v.clear();
    //=====================================================================level9
    int array9[4][4] = {
        { 1, 0, 1, 0 },
        { 1, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 1, 0, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array9[i][j]);
        v.push_back(v1);
    }
    mData.insert(9, v);
    v.clear();
    //=====================================================================level10
    int array10[4][4] = {
        { 1, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 0, 0, 1, 1 },
        { 1, 1, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array10[i][j]);
        v.push_back(v1);
    }
    mData.insert(10, v);
    v.clear();
    //=====================================================================level11
    int array11[4][4] = {
        { 0, 1, 1, 0 },
        { 1, 0, 0, 1 },
        { 1, 0, 0, 1 },
        { 0, 1, 1, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array11[i][j]);
        v.push_back(v1);
    }
    mData.insert(11, v);
    v.clear();
    //=====================================================================level12
    int array12[4][4] = {
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 0, 0, 0, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array12[i][j]);
        v.push_back(v1);
    }
    mData.insert(12, v);
    v.clear();
    //=====================================================================level13
    int array13[4][4] = {
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 1, 1, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array13[i][j]);
        v.push_back(v1);
    }
    mData.insert(13, v);
    v.clear();
    //=====================================================================level14
    int array14[4][4] = {
        { 1, 0, 1, 1 },
        { 0, 1, 0, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array14[i][j]);
        v.push_back(v1);
    }
    mData.insert(14, v);
    v.clear();
    //=====================================================================level15
    int array15[4][4] = {
        { 0, 1, 0, 1 },
        { 1, 0, 0, 0 },
        { 1, 0, 0, 0 },
        { 0, 1, 0, 1 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array15[i][j]);
        v.push_back(v1);
    }
    mData.insert(15, v);
    v.clear();
    //=====================================================================level16
    int array16[4][4] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 0, 1, 1, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array16[i][j]);
        v.push_back(v1);
    }
    mData.insert(16, v);
    v.clear();
    //=====================================================================level17
    int array17[4][4] = {
        { 0, 1, 1, 1 },
        { 0, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 1, 1, 1, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array17[i][j]);
        v.push_back(v1);
    }
    mData.insert(17, v);
    v.clear();
    //=====================================================================level18
    int array18[4][4] = {
        { 0, 0, 0, 1 },
        { 0, 0, 1, 0 },
        { 0, 1, 0, 0 },
        { 1, 0, 0, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array18[i][j]);
        v.push_back(v1);
    }
    mData.insert(18, v);
    v.clear();
    //=====================================================================level19
    int array19[4][4] = {
        { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 1, 1 },
        { 0, 0, 0, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array19[i][j]);
        v.push_back(v1);
    }
    mData.insert(19, v);
    v.clear();
    //=====================================================================level20
    int array20[4][4] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };
    for (int i = 0; i < 4; i++) {
        QVector<int> v1;
        for (int j = 0; j < 4; j++) v1.push_back(array20[i][j]);
        v.push_back(v1);
    }
    mData.insert(20, v);
    v.clear();

    //测试数据
//    for(QMap<int, QVector<QVector<int>>>::iterator it = mData.begin();
//         it != mData.end();
//         it++) {
//         for(QVector<QVector<int>>::iterator it2 = (*it).begin();
//             it2!= (*it).end();
//             it2++) {
//            for(QVector<int>::iterator it3 = (*it2).begin();
//                  it3 != (*it2).end();
//                  it3++) {
//                qDebug() << *it3;
//            }
//         }
//         qDebug() << endl;
//    }

}


