/*************************************************************************
	> File Name: doubleLinkLoop/doubleLinkLoop.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Mon Oct 14 12:50:47 2024
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;


Node* InitLink(){
    Node* headNode=(Node*)malloc(sizeof(Node));
    headNode->data=0;
    headNode->next=headNode;
    headNode->pre=headNode;
    return headNode;
}

void headInsert(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if (L->data==0) {
        node->next=L;
        node->pre=L;
        L->next=node;
        L->pre=node;
        L->data ++;
    }else {
        node->next=L->next;
        node->pre=L;
        L->next->pre=node;
        L->next=node;
        L->data ++;
    }
}

void tailInsert(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if (L->data==0) {
        node->next=L;
        node->pre=L;
        L->next=node;
        L->pre=node;
        L->data ++;
    }else {
        node->next=L;
        Node* curNode=L->next;
        while (curNode->next!=L) {
            curNode=curNode->next; 
        }
        node->pre=curNode;
        curNode->next=node;
        L->data ++;
    }
}

void delElement(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    if (L->data == 0) {
        printf("no arguments in link\n");
    }else {
        Node* currentNode=L->next;
        while (currentNode->data != data) {
            currentNode=currentNode->next;
        }
        currentNode->pre->next=currentNode->next;
        currentNode->next->pre=currentNode->pre;
        free(currentNode);
        L->data --;
    }

}

void printLink(Node* L){
    Node* cur=L->next;
    while (cur != L) {
        printf("%d->",cur->data); 
        cur=cur->next;
    }
    printf("NULL\n");
}


int main(){
    Node* L=InitLink();
    headInsert(L,1);
    headInsert(L,2);
    headInsert(L,3);
    headInsert(L,4);
    tailInsert(L,5);
    delElement(L,2);
    printLink(L);
    printf("%d",L->next->next->next->pre->data);
}
