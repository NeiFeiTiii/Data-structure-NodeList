// 输入在第一行给出第一个多项式POLYA的系数和指数，并以0,0 结束第一个多项式的输入；
// 在第二行出第一个多项式POLYB的系数和指数，并以0,0 结束第一个多项式的输入。
// Created by 相耀 on 2023/9/26.
// 多项式的加法
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    int pow;
    struct Node* next;
} Node;

int CreatTail(Node *head) {   //尾插法
    Node * r, * newNode;
    r = head;
    int data = 0;
    int pow = 0;
    scanf("%d,%d", &data,&pow);
    if(pow == 0 && data == 0) return 0;
    while (1) {
        newNode = (Node * )malloc(sizeof(Node));
        newNode->data = data;
        newNode->pow = pow;
        newNode->next = r->next;
        r->next = newNode;
        r = newNode;
        scanf("%d,%d", &data,&pow);
        if(pow == 0 && data == 0) break;
    }
    r->next = NULL;
    return 1;
}

int print(Node *head) {   //打印
    Node *p;
    p = head->next;
    if(p == NULL) {
        printf("NULL");
        return 1;
    }
    while (p) {
        if(p->data == 0) {
            p = p->next;
            continue;
        }
        else printf("%d,%d ", p->data,p->pow);
        p = p->next;
    }
    return 0;
}

void Add(Node *head1,Node *head2){
    Node *p,*q;
    Node *l;
    p = head1->next;
    q = head2->next;
    while(p) {
        while (q) {
            if(p->pow == q->pow) {
                p->data = p->data + q->data;
                q = q->next;
            }
            else q = q->next;
        }
        q = head2->next;
        p = p->next;
    }
    p = head1->next;
    q = head2->next;
    while (q){
        while (p){
            if(q->pow > p->pow && q->pow < p->next->pow){
                l = (Node * )malloc(sizeof(Node));
                l->data = q->data;
                l->pow = q->pow;
                l->next = p->next;
                p->next = l;
                break;
            }
            else p = p->next;
        }
        p = head1->next;
        q = q->next;
    }
}

void Sort(Node *node){
    Node *p,*q;
    int temp_d;
    int temp_p;
    for(p = node->next;p!=NULL && p->next != NULL;p=p->next){
        for(q = p->next;q!=NULL;q=q->next){
            if(q->pow < p->pow){
                temp_d = q->data;
                q->data = p->data;
                p->data = temp_d;
                temp_p = q->pow;
                q->pow = p->pow;
                p->pow = temp_p;
            }
        }
    }
}

int main(){
    Node L;
    Node N;
    int l1 = CreatTail(&L);
    int l2 = CreatTail(&N);
    if(l1 == 0 && l2 ==0)
        printf("\n");
    else {
        Sort(&L);
        Sort(&N);
        Add(&L, &N);
        print(&L);
    }
}