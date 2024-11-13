/*************************************************************************
	> File Name: doubleLink.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Sun Oct 13 19:33:06 2024
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

Node* initLink(){
    Node* headNode=(Node*)malloc(sizeof(Node));
    headNode->data=0;
    headNode->pre=NULL;
    headNode->next=NULL;
    return headNode;
}

void headInsert(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if (L->data==0) {
        //链表为空时 
        node->next=L->next;
        node->pre=L;
        L->next=node;
        L->data ++;
    }else {
        node->pre=L;
        node->next=L->next;
        L->next->pre=node;
        L->next=node;
        L->data ++;    
    }

}

 void tailInsert(Node* L,int data){
     Node* node=(Node*)malloc(sizeof(Node));
     node->data=data;
     node->next=NULL;
     Node* currentNode=L;
     while (currentNode->next){
         currentNode=currentNode->next;
     } 
     currentNode->next=node;
     node->pre=currentNode;
     L->data ++;
 }

void delElement(Node* L,int data){
    Node* preNode=L;
    Node* currentNode=L->next;
    while (currentNode->data != data) {
        preNode=currentNode;
        currentNode=currentNode->next;
    }
    preNode->next=currentNode->next;
    free(currentNode);
    L->data --;
}

void printLisst(Node* L){
    Node* currentNode=L->next;
    while (currentNode) {
        printf("%d->",currentNode->data); 
        currentNode=currentNode->next;
    }
    printf("NULL\n");
}


int main(){
    Node* L = initLink();
    headInsert(L,1);
    headInsert(L,2);
    headInsert(L, 3);
    tailInsert(L,4);
    delElement(L,2);
    printLisst(L);
    printf("%d",L->data);
}
