#ifndef SLICE_SLICE_UNICODE_H
#define SLICE_SLICE_UNICODE_H

    #include "../slice_unicode/slice_unicode.h"
    #include <stdint.h>

    // unicode切片结构体，支持最多6,5536个字符，参考go切片、rust切片等切片设计
    typedef struct {
        uint32_t 长度;
        uint32_t 容量;
        unicode切片 * 数据区; //指向unicode切片数组的数据指针
    } unicode切片动态数组;

    // 提供以下操作函数
    void unicode切片动态数组_初始化(unicode切片动态数组 * 数组指针, int 初始容量);
    void unicode切片动态数组_清空(unicode切片动态数组 * 数组指针);
    void unicode切片动态数组_重置(unicode切片动态数组 * 数组指针);
    void unicode切片动态数组_扩容(unicode切片动态数组 * 数组指针, int 期望容量);
    void unicode切片动态数组_追加(unicode切片动态数组 * 数组指针, unicode切片 待追加切片);
    void unicode切片动态数组_文件打印(unicode切片动态数组 * 数组指针, FILE * 输出文件);
    void unicode切片动态数组_文件序列化打印(unicode切片动态数组 * 数组指针, FILE * 输出文件);
    
#endif