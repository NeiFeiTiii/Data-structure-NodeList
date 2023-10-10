// 链表 + pta3
// Created by 相耀 on 2023/9/22.
//
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*Node * InitList() {   //新建一个链表
    Node * head = (Node * )malloc(sizeof(Node));
    head->next = NULL;
    return head;
}*/

void CreatTail(Node *head) {   //尾插法
    Node * r, * newNode;
    r = head;
    int data;
    scanf("%d", &data);
    while (data != -1) {
        newNode = (Node * )malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = r->next;
        r->next = newNode;
        r = newNode;
        scanf("%d", &data);
    }
    r->next = NULL;
}

void CreatHead(Node *head) {     //头插法
    Node *newNode;
    int data;
    scanf("%d", &data);
    while (data != -1) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head->next;
        head->next = newNode;
        scanf("%d", &data);
    }
}

int NodeClear(Node *head){    //清空链表
    Node *p, *q;
    p = head;
    q = NULL;
    while (p){
        q = p;
        free(p);
        p = q->next;
    }
    return 1;
}

int reverseNode(Node *head){    //反转链表
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    Node *p = NULL;
    Node *q = head->next;
    Node *next ;
    while (q != NULL) {
        next = q->next;
        q->next = p;
        p = q;
        q = next;
    }
    head->next=p;
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
        if(p->next == NULL)
        printf("%d\n", p->data);
        else printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}

void MergeList(Node *head1,Node *head2){    //两个归并成一个
    Node *pa;
    Node *pb;
    Node *pc;
    pa = head1->next;
    pb = head2->next;
    pc = head1;
    while (pa!=NULL && pb!=NULL){
        if(pa->data<=pb->data){
            pc->next = pa; pc = pa;pa = pa->next;
        }
        else{
            pc->next = pb;pc = pb;pb = pb->next;
        }
    }
    if (pa != NULL) {   // 根据实际情况选择是否使用else和if来判断链表长度是否相等。
        // 这里使用if和else是等价的。
        pc->next = pa ? pa : pb;
    } else {
        pc->next = pb ? pb : pa;
    }
}

int main(){
    Node L;
    Node N;
    //InitList(&L);
    //InitList(&N);
    CreatTail(&L);
    CreatTail(&N);
    MergeList(&L,&N);
    print(&L);
}