//
// Created by 相耀 on 2023/11/6.
//
#include <stdio.h>


typedef struct {
    int i,j;
    int e;
}Tuple;

typedef struct {
    Tuple data[10000];
    int rows,cols,tu;
}TSMatrix;

void CreateTS(TSMatrix *TS, int row, int col, int t){    //创建三元组
    TS->rows = row;
    TS->cols = col;
    TS->tu = t;
}

void FastTranSMatrix(TSMatrix *M,TSMatrix *T,int column){  //快速转置,M is origin
    int num[column+1];
    int cpot[column+1];
    int col;
    int q;
    if(T->tu){
        for (col = 1;col<=M->cols;col++)
            num[col] = 0;
        for (int i = 1;i<=M->tu;i++)
            num[M->data[i].j]++;
        cpot[1] = 1;
        for(col = 1;col<=M->cols;col++)
            cpot[col] = cpot[col - 1] + num[col - 1];
        for(int p = 1;p<=M->tu;p++){
            col = M->data[p].j;
            q = cpot[col];
            T->data[q].i = M->data[p].j;
            T->data[q].j = M->data[p].i;
            T->data[q].e = M->data[p].e;
            cpot[col]++;
        }
    }
}


int main(){

    TSMatrix ts,ns;
    int row,col,t;
    scanf("%d %d %d",&row,&col,&t);
    CreateTS(&ts, row, col, t);
    CreateTS(&ns, row, col, t);
    for (int i = 0;i<t;i++){
        scanf("%d %d %d",&ts.data[i+1].i,&ts.data[i+1].j,&ts.data[i+1].e);
    }
    FastTranSMatrix(&ts,&ns,col);
    for (int i = 0; i < t; ++i) {
        if(i == t-1)
            printf("%d %d %d",ns.data[i].i,ns.data[i].j,ns.data[i].e);
        else printf("%d %d %d\n",ns.data[i].i,ns.data[i].j,ns.data[i].e);
    }
}