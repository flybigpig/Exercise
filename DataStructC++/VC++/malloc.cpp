#include <stdio.h>
#include <stdlib.h>

int main() {
    // 分配一个能存储10个整数的内存块
    int *ptr = (int *)malloc(10 * sizeof(int));
    if (ptr == NULL) {
        // 内存分配失败
        printf("内存分配失败！\n");
        return 1;
    }
    // 给分配的内存块赋值
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
    }
    // 打印分配的内存块中的值
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    // 释放分配的内存
    free(ptr);
    return 0;
}