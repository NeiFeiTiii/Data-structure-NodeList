//两个顺序表内容，求集合交集
// Created by 相耀 on 2023/9/22.
//
#include <stdio.h>
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
}SqList;

void Printpp(SqList c);

void InitList(SqList *L){
    L->length = 0;
}

int ListInsert(SqList *L,int i,int e){
    if(i<1||i > L->length+1||L->length >= MAXSIZE)
        return 0;
    for (int j = L->length; j >=i ; j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return 1;
}

void PrintList(SqList A,SqList B){
    int flag = 1;
    SqList C;
    InitList(&C);
    for (int i = 0;i<A.length;i++){
        for(int j = 0;j<B.length;j++){
            if(B.data[j] ==A.data[i]) {
                ListInsert(&C, flag, B.data[j]);
                flag++;
                break;
            }
        }
    }
    if(C.length>0)
        Printpp(C);
    else printf("NUll");
}

void Printpp(SqList L) {
    for (int i = 0; i < L.length; i++) {
        if(i == L.length-1)
            printf("%d", L.data[i]);
        else printf("%d ", L.data[i]);
    }
    printf("\n");
}


int main(){
    SqList A,B;
    InitList(&A);
    InitList(&B);
    int n,m;
    scanf("%d %d",&n,&m);
    int x;
    for (int i = 1; i <= n; i++) {
        scanf("%d",&x);
        ListInsert(&A,i,x);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d",&x);
        ListInsert(&B,i,x);
    }
    PrintList(A,B);
}