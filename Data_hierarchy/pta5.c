// 输入若干个不超过100的整数，建立单链表，
// 然后将链表中所有结点的链接方向逆置，
// 要求仍利用原表的存储空间。输出逆置后的单链表。
// Created by 相耀 on 2023/9/25.
#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void CreateTail(Node *head,int n){
    Node *r,*newNode;
    r = head;
    int data;
    for(int i = 0;i<n;i++){
        scanf("%d",&data);
        newNode = (Node *) malloc(sizeof (Node));
        newNode->data = data;
        newNode->next = r->next;
        r->next = newNode;
        r = newNode;
    }
    r->next = NULL;
}

int reverseNode(Node *head){    //链表倒过来
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

void Print(Node *head){
    Node *p;
    p = head->next;
    while (p){
        if(p->next == NULL)
            printf("%d\n",p->data);
        else printf("%d ",p->data);
        p = p->next;
    }
}

int main(){
    int length,club;
    Node L;
    scanf("%d",&club);
    for (int i = 0; i < club; ++i) {
        scanf("%d",&length);
        CreateTail(&L,length);
        reverseNode(&L);
        Print(&L);
    }
}