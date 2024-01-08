/*
//
// Created by 相耀 on 2023/12/20.
//
#include <stdio.h>
#include <malloc.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode;

void Init(BiTNode *t,int x){
    t->data = x;
    t->rchild = NULL;
    t->lchild = NULL;
}

BiTNode *insertNode(BiTNode *t,BiTNode *s){
    BiTNode *p,*q;
    if(t==NULL)
        return s;
    p = t;
    while (p){
        q = p;
        if(s->data == p->data)
            return t;
        if(s->data < p->data)
            p = p->rchild;
        else p = p->rchild;
    }
    if(s->data<q->data)
        q->lchild = s;
    else q->rchild = s;
    return t;
}

void Search(BiTNode *Head,int x){
    BiTNode *p,*q;
    p = Head;
    if(Head == NULL){
        printf("It does not exist.");
        return;
    }
    if(Head->data == x) {
        printf("It doesn't have parent.");
        return;
    }
    while(p){
        if(x == p->data){
            printf("%d",q->data);
            return;
        }
        q = p;
        if(x>p->data)
            p = p->rchild;
        else p=p->lchild;

    }
    printf("It does not exist.");
}

int main(){
    int n,x;
    scanf("%d",&n);
    BiTNode *SearchTree;
    scanf("%d",&x);
    Init(SearchTree,x);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d",&x);
        BiTNode *insert = (BiTNode *) malloc(sizeof(BiTNode));
        Init(insert,x);
        SearchTree = insertNode(SearchTree,insert);
    }
    scanf("%d",&x);
    Search(SearchTree,x);
}*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode;

void Init(BiTNode *t, int x) {
    t->data = x;
    t->lchild = t->rchild = NULL;
}

BiTNode *insertNode(BiTNode *t, BiTNode *s) {
    if (t == NULL) {
        t = (BiTNode *)malloc(sizeof(BiTNode));
        Init(t, s->data);
        return t;
    }
    if (s->data < t->data) {
        t->lchild = insertNode(t->lchild, s);
    } else if (s->data > t->data) {
        t->rchild = insertNode(t->rchild, s);
    }
    else if(s->data == t->data){
        return t;
    }// If data is same, you may choose to insert or not, based on your requirements.
    return t;
}

void Search(BiTNode *Head, int x) {
    BiTNode *q;
    if (Head == NULL) {
        printf("It does not exist.\n");
        return;
    }
    if (Head->data == x) {
        printf("It doesn't have parent.\n");
        return;
    }
    BiTNode *p = Head;
    while (p) {
        if (x == p->data) {
            printf("%d\n", q->data);
            return;
        }
        q = p;
        if (x < p->data) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    printf("It does not exist.\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    BiTNode *root = NULL; // Initialize the root as NULL. This will be our SearchTree.
    scanf("%d", &x);
    root = (BiTNode *)malloc(sizeof(BiTNode)); // Allocate memory for the root node.
    Init(root, x); // Initialize the root node.
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &x);
        BiTNode *insert = (BiTNode *)malloc(sizeof(BiTNode)); // Allocate memory for the new node.
        Init(insert, x); // Initialize the new node.
        root = insertNode(root, insert); // Insert the new node into the binary search tree.
    }
    scanf("%d", &x);
    Search(root, x);
    free(root);
    return 0;
}