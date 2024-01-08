#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

#define MAX_DIM 8

typedef struct {
    int *base;          //基址
    int dim;            //数组维数
    int *bounds;        //维界基址
    int *constants;     //常量基址
}Array;

void InitArray (Array *A, int dim, ...){    //含有一个形参和省略号的函数
    if(dim < 1 || dim > MAX_DIM){
        printf("Dim is illegal.\n");
        return;
    }
    va_list ap;                             //声明一个储存参数的对象
    A->dim = dim;
    A->bounds = (int *)malloc(dim * sizeof (int));
    int ElemTotal = 1;

    va_start(ap, dim);

    for(int i = 0;i < dim;i++){             //存放每个维界有多少元素
        A->bounds[i] = va_arg(ap, int);
        if(A->bounds[i] < 0){
            printf("bounds have an error!\n");
            return;
        }
        ElemTotal *= A->bounds[i];
    }

    va_end(ap);

    A->base = (int *) malloc(ElemTotal * sizeof (int));
    A->constants = (int *) malloc(dim * sizeof (int));
    A->constants[dim - 1] = 1;
    for(int i = dim - 2; i>=0; i--){        //设置常量基址
        A->constants[i] = A->bounds[i+1] * A->constants[i+1];
    }
    printf("%d\n",ElemTotal);
}//Init, 没有写那些动态分配空间失败的if

void DestoryArray(Array *A){
    free(A->base);
    A->base = NULL;
    free(A->bounds);
    A->bounds = NULL;
    free(A->constants);
    A->constants = NULL;
}//Destory

int Locate(Array *A, va_list ap){
    int off = 0;
    int ind;
    for(int i = 0; i < A->dim; i++){
        ind = va_arg(ap, int);
        if(ind < 0 || ind >= A->bounds[i]){
            printf("ind has an error\n");
            return -1;
        }
        off += A->constants[i] * ind;       //对应书本上求相对坐标的 “基址+求和（Ci*Ji）”
    }
    //printf("locate is %d\n",off);
    return off;
}//relative address

int Value(Array *A, ...){
    int e;
    va_list ap;
    va_start(ap, e);
    int result = Locate(A, ap);
    if(result < 0) {
        printf("error,i will output '-1000'\n");
        return -1000;
    }
    e = *(A->base + result);
    va_end(ap);
    printf("relative address is %d\n",result);  //打印相对地址
                                                        // Assign以及Locate中可
    return e;
}//取值

void Assign(Array *A, int e, ...) {
    va_list ap;
    va_start(ap, e);
    int result = Locate(A, ap);
    if (result < 0) {
        printf("error\n");
        return;
    }
    *(A->base + result) = e;
    va_end(ap);
}//置入元素

int main(){
    Array arr;
    InitArray(&arr, 2, 3, 2);   //意为创建二维数组，3行2列，可以自行修改
    Assign(&arr,520, 2, 0);       //向数组中（2，0）的位置传入520，作为此处元素
    int elem;
    elem = Value(&arr, 2, 0);       //  读取（2，0）位置的元素
    printf("%d",elem);          //上面的传入传出只作为一个参考，可以尝试循环输入元素
    DestoryArray(&arr);
    /*elem = Value(&arr, 2, 2);
    printf("%d",elem);*/            //已经销毁，不能传入和输出
}