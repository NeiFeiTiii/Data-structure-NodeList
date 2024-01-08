//
// Created by DDD on 2023/11/7.
//
#include <stdio.h>

#define MAXSIZE 1000

typedef struct {
    int i,j;
    int e;
}Tuple;

typedef struct {
    Tuple data[MAXSIZE];
    int nZeros;
}TSMatrix;

int main(){
    int row,col;
    scanf("%d %d",&row,&col);
    TSMatrix TS1;
    TSMatrix TS2;
    TSMatrix Sum;
    scanf("%d",&TS1.nZeros);
    for(int i = 0;i<TS1.nZeros;i++){
        scanf("%d %d %d",&TS1.data[i].i,&TS1.data[i].j,&TS1.data[i].e);
    }
    scanf("%d",&TS2.nZeros);
    for(int i = 0;i<TS2.nZeros;i++){
        scanf("%d %d %d",&TS2.data[i].i,&TS2.data[i].j,&TS2.data[i].e);
    }

    int arr1[row][col];
    int arr2[row][col];
    int arr3[row][col];
    for(int i = 0;i<row;i++) {
        for (int j = 0; j < col; ++j) {
            arr1[i][j] = 0;
            arr2[i][j] = 0;
        }
    }
    for(int i = 0; i<TS1.nZeros;i++){
        arr1[TS1.data[i].i][TS1.data[i].j] = TS1.data[i].e;
    }
    for (int i = 0; i < TS2.nZeros; ++i) {
        arr2[TS2.data[i].i][TS2.data[i].j] = TS2.data[i].e;
    }
    for(int i = 0;i<row;i++) {
        for (int j = 0; j < col; ++j) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    int nz = 0;
    for(int i = 0;i<row;i++) {
        for (int j = 0; j < col; j++) {
            if(arr3[i][j] != 0){
                Sum.data[nz].i = i;
                Sum.data[nz].j = j;
                Sum.data[nz].e = arr3[i][j];
                nz++;
            }
        }
    }
    Sum.nZeros = nz;
    printf("%d\n",nz);
    for (int i = 0; i < Sum.nZeros; ++i) {
        printf("%d %d %d\n",Sum.data[i].i,Sum.data[i].j,Sum.data[i].e);
    }
}