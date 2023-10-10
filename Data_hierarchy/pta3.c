//
// Created by 相耀 on 2023/9/24.
//
#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

/*Node *InitList(){
    Node * head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    return head;
}*/

void CreatTail(Node *head,int n){
    Node *r,*newNode;
    r = head;
    int data;
    for (int i = 0; i < n; i++){
        scanf("%d",&data);
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = r->next;
        r->next = newNode;
        r = newNode;
    }
    r->next = NULL;
}

void print(Node *head){
    Node *p;
    p = head->next;
    while (p){
        if(p->next == NULL)
            printf("%d\n",p->data);
        else printf("%d ",p->data);
        p = p->next;
    }
}

int Insert(Node *head){
    int ins,flag;
    scanf("%d",&ins);
    Node *pa,*pb;
    pb = (Node *) malloc(sizeof (Node));
    pa = head->next;
    flag = 1;
    if(pa == NULL){
        pb->data = ins;
        head->next = pb;
        pb->next =NULL;
        return 0;
    }
    while (pa->next!=NULL){
        if((pa->data < ins && ins < pa->next->data)){
            pb->data = ins;
            pb->next = pa->next;
            pa->next = pb;
            return 1;
        }
        else if(ins<pa->data && flag == 1){
            pb->data = ins;
            pb->next = head->next;
            head->next = pb;
            return 2;
        }
        else pa = pa->next;
        flag++;
    }
    if(pa->data< ins) {
        pb->data = ins;
        pa->next = pb;
        pb->next = NULL;
        return 4;
    }
    return 5;
}

int main(){
    Node L;
    int n;
    scanf("%d",&n);
    //InitList(&L);
    //InitList(&N);
    CreatTail(&L,n);
    //print(&L);
    Insert(&L);
    print(&L);
}
