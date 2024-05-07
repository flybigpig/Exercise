//
// Created by YT_FLY on 2024/5/7.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 要生成和返回随机数的函数 */
int * getRandom( )
{
    static int  r[10];
    int i;

    /* 设置种子 */
    srand( (unsigned)time( NULL ) );
    for ( i = 0; i < 10; ++i)
    {
        r[i] = rand();
        printf("%d\n", r[i] );
    }

    return r;
}

int main ()
{
    int  var = 20;   /* 实际变量的声明 */
    int  *ip;        /* 指针变量的声明 */

    ip = &var;  /* 在指针变量中存储 var 的地址 */

    printf("var 变量的地址: %p\n", &var  );

    /* 在指针变量中存储的地址 */
    printf("ip 变量存储的地址: %p\n", ip );

    /* 使用指针访问值 */
    printf("*ip 变量的值: %d\n", *ip );

    int *p;
    int i;

    p = getRandom();
    for ( i = 0; i < 10; i++ )
    {
        printf("*(p + [%d]) : %d\n", i, *(p + i) );
    }


    return 0;
}


