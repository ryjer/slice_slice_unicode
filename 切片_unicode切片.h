#ifndef 切片_UNICODE切片_H
#define 切片_UNICODE切片_H

    #include "../unicode切片/unicode切片.h"
    #include <stdint.h>
    #include <stdlib.h>
    #include <stdio.h>

    // unicode切片结构体，支持最多6,5536个字符，参考go切片、rust切片等切片设计
    typedef struct {
        uint32_t 长度;
        uint32_t 容量;
        unicode切片 * 数据区; //指向unicode切片数组的数据指针
    } unicode切片动态数组;
    
    // 提供以下操作函数

    unicode切片动态数组 创建unicode切片动态数组(int 初始容量);
    void unicode切片动态数组_初始化(unicode切片动态数组 * 数组指针, int 初始容量); //√已测试
    void unicode切片动态数组_清空(unicode切片动态数组 * 数组指针); //√已测试
    void unicode切片动态数组_重置(unicode切片动态数组 * 数组指针); //√已测试
    void unicode切片动态数组_扩容(unicode切片动态数组 * 数组指针, int 期望容量); //√已测试
    void unicode切片动态数组_追加(unicode切片动态数组 * 数组指针, unicode切片 待追加切片); //√已测试
    void unicode切片动态数组_文件打印(unicode切片动态数组 * 数组指针, FILE * 输出文件); //√已测试
    void unicode切片动态数组_文件序列化打印(unicode切片动态数组 * 数组指针, FILE * 输出文件); //√已测试
    // 以下为纯函数

    int unicode切片动态数组_遍历搜索(unicode切片动态数组 *被搜索数组, unicode切片 目标切片); //√已测试
#endif