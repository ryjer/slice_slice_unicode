#include "slice_slice_unicode.h"
#include <stdio.h>

// gcc -g -Wall test.c slice_slice_unicode.c ../slice_unicode/slice_unicode.c ../utf8_unicode/utf8_unicode.c && ./a.out
// 测试用例
int main() {
    unicode切片动态数组 切片数组;
    unicode切片 切片;
    FILE * 输出文件 = stdout;
    // 初始化切片 切片数组
    unicode切片_初始化(&切片, 8);
    unicode切片动态数组_初始化(&切片数组, 8);
    // 打印提示
    fprintf(输出文件, "初始化与序列化：\n");
    unicode切片动态数组_文件序列化打印(&切片数组, 输出文件);
    fputc('\n', 输出文件);
    // test.txt 文件字符追加，一行一个切片
    fprintf(输出文件, "文件行追加测试，舍弃行尾的换行符\n");
    // utf8文件读取
    FILE * 输入文件 = fopen("test.txt", "r");
    unicode字符 字符; // 读取utf8编码
    do{
        字符 = utf8转unicode(文件_读取utf8字符(输入文件));
        unicode切片_追加(&切片, 字符);
        // 换行检查，遇到换行或文件结束，就向数组追加一项，并重置切片
        if (字符==EOF || 字符=='\n') {
            if (字符=='\n') { 切片.长度--; }
            unicode切片动态数组_追加(&切片数组, unicode切片_复制(&切片));
            unicode切片_重置(&切片);
        }
    }while(字符!=EOF);
    // 序列化测试
    fprintf(输出文件, "序列化测试：\n");
    unicode切片动态数组_文件序列化打印(&切片数组, 输出文件);
    fputc('\n', 输出文件);
    // 文件打印测试
    fprintf(输出文件, "文件打印测试：\n");
    unicode切片动态数组_文件打印(&切片数组, 输出文件);
    fputc('\n', 输出文件);
    // 重置测试
    fprintf(输出文件, "重置测试：\n");
    unicode切片动态数组_重置(&切片数组);
    unicode切片动态数组_文件序列化打印(&切片数组, 输出文件);
    fputc('\n', 输出文件);
}