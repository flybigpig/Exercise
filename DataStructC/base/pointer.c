//
// Created by YT_FLY on 2024/5/7.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Ҫ���ɺͷ���������ĺ��� */
int * getRandom( )
{
    static int  r[10];
    int i;

    /* �������� */
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
    int  var = 20;   /* ʵ�ʱ��������� */
    int  *ip;        /* ָ����������� */

    ip = &var;  /* ��ָ������д洢 var �ĵ�ַ */

    printf("var �����ĵ�ַ: %p\n", &var  );

    /* ��ָ������д洢�ĵ�ַ */
    printf("ip �����洢�ĵ�ַ: %p\n", ip );

    /* ʹ��ָ�����ֵ */
    printf("*ip ������ֵ: %d\n", *ip );

    int *p;
    int i;

    p = getRandom();
    for ( i = 0; i < 10; i++ )
    {
        printf("*(p + [%d]) : %d\n", i, *(p + i) );
    }


    return 0;
}


