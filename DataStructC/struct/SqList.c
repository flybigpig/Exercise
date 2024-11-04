//
// Created by YT_FLY on 2024/5/7.
//

#define LIST_INIT_SIZE 1000 // 基础容量

#define LISTINCREMENT 50 // 分配增量

#include <stdio.h>
#include <string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book = {"C 语言", "RUNOOB", "编程语言", 123456};

typedef struct
{
    //    ElemType *elem;
    char site[50];
    int length;
    int listSize;
    struct Books books;

} SqList;

int main()
{
    SqList sqlist;

    sqlist.length = 1;
    sqlist.listSize = 1;
    sqlist.books = book;

    strcpy(sqlist.site, "C Programming");
    printf("%d\n", sqlist.listSize);

    printf("%d\n", sqlist.books.book_id);

    printf("%s\n", sqlist.books.title);
    printf("%s\n", sqlist.books.author);
    printf("%s\n", sqlist.books.subject);

    printf("%s\n", sqlist.site);
    return 0;
}
