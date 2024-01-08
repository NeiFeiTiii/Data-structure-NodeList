//
// Created by 相耀 on 2023/11/6.
//
#include <stdio.h>

#define MAXSIZE 80

typedef struct {
    int i,j;
    int e;
}Tuple;

typedef struct {
    Tuple data[MAXSIZE];
    int rows,cols,nZeros;
}TSMatrix;

void CreateTS(TSMatrix *TS, int row, int col, int NotZ){    //创建三元组
    TS->rows = row;
    TS->cols = col;
    TS->nZeros = NotZ;
    for(int i = 0;i<NotZ;i++){
        scanf("%d %d %d",&TS->data[i].i,&TS->data[i].j,&TS->data[i].e);
    }
}

void PrintTS(TSMatrix *ts){     //打印三元组矩阵
    for (int i = 0; i < ts->nZeros; ++i) {
        printf("%d %d %d\n",ts->data[i].i,ts->data[i].j,ts->data[i].e);
    }
}

void Add(TSMatrix *A, TSMatrix *B, TSMatrix *C, int row, int col){
    int No1 = 0, No2 = 0 ,No3= 0;
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; ++j) {
            if(A->data[No1].i == i && A->data[No1].j == j){
                if(B->data[No2].i == i && B->data[No2].j == j){
                    C->data[No3].i = i;
                    C->data[No3].j = j;
                    C->data[No3].e = A->data[No1].e + B->data[No2].e;
                    No1++;
                    No2++;
                    if(C->data[No3].e != 0) {
                        No3++;
                    }
                }
                else{
                    C->data[No3].i = i;
                    C->data[No3].j = j;
                    C->data[No3].e = A->data[No1].e;
                    No1++;
                    No3++;
                }
            }
            if(B->data[No2].i == i && B->data[No2].j == j){
                C->data[No3].i = i;
                C->data[No3].j = j;
                C->data[No3].e = B->data[No2].e;
                No2++;
                No3++;
            }
        }
    }
    C->nZeros = No3;
}


int main(){
    int row,col;
    scanf("%d %d",&row,&col);
    int nZ1,nZ2;
    TSMatrix TS1,TS2,Sum;
    scanf("%d",&nZ1);
    CreateTS(&TS1,row,col,nZ1);
    scanf("%d",&nZ2);
    CreateTS(&TS2,row,col,nZ2);
    CreateTS(&Sum,row,col,0);
    Add(&TS1, &TS2, &Sum, row, col);
    printf("%d\n",Sum.nZeros);
    PrintTS(&Sum);
}