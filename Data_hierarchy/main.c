//顺序表
#include <stdio.h>
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
}SqList;

void InitList(SqList *L)  //初始化
{
    L->length = 0;

}

int ListInsert(SqList *L, int i, int e) {
    if (i < 1 || i > L->length + 1 || L->length >= MAXSIZE) {
        return 0; // 插入位置不合法或顺序表已满，插入失败
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1]; // 将插入位置及之后的元素后移一位
    }
    L->data[i - 1] = e; // 将新元素插入指定位置
    L->length++; // 顺序表长度加1
    return 1; // 插入成功
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        if(i == L.length-1)
            printf("%d", L.data[i]);
        else printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    InitList(&L);
    int n;
    scanf("%d",&n);
    int x;
    for (int i = 1;i<=n;i++)
    {
        scanf("%d",&x);
        ListInsert(&L,i,x);
    }
    PrintList(L);
}
