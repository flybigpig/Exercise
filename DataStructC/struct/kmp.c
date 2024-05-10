//
// Created by YT_FLY on 2024/5/10.
//

#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Found pattern at index %d \n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}


char *substring(char *ch, int pos, int length) {
    //定义字符指针 指向传递进来的ch地址
    char *pch = ch;
    //通过calloc来分配一个length长度的字符数组，返回的是字符指针。
    char *subch = (char *) calloc(sizeof(char), length + 1);
    int i;
    //只有在C99下for循环中才可以声明变量，这里写在外面，提高兼容性。
    pch = pch + pos;
//是pch指针指向pos位置。
    for (i = 0; i < length; i++) {
        subch[i] = *(pch++);
//循环遍历赋值数组。
    }
    subch[length] = '\0';//加上字符串结束符。
    return subch;       //返回分配的字符数组地址。
}

void strSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    printf(" %d  %d \n", M, N);
    int i = 0;
    for (i; i <= (N - M); i++) {
        char *s = substring(txt, i, i + strlen(pat));
//        printf("%s   \n", s);
        if (strcasecmp(pat, s) == 0) {
            printf("Found pattern at index %d \n", i);
        }
    }
}


int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);
    KMPSearch(pat, txt);
    // 非
    strSearch(pat, txt);
    return 0;
}