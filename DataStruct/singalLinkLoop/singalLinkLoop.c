/*************************************************************************
	> File Name: singlLinkwhile.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Sat Oct 12 22:01:58 2024
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;


Node* InitzaLink(){
    Node* headNode=(Node*)malloc(sizeof(Node));
    headNode->data=0;
    headNode->next=headNode;
    return headNode;
}

void headInsert(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=L->next;
    L->next=node;
    L->data ++;
}

void tailInsert(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    Node* currentNode=L->next;
    while (currentNode->next != L) {
        currentNode=currentNode->next;
    }
    currentNode->next=node;
    node->next=L;
    L->data ++;
}

void delNode(Node* L,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    Node* preNode=L;
    Node* currentNode=L->next;
    while (currentNode != L) {
        if (currentNode->data!=data) {
            preNode=currentNode;
            currentNode=currentNode->next;
        }else {
            preNode->next=currentNode->next;
            free(currentNode);
            break;
        } 

    }
}

void printfList(Node* L){
    Node* node=L->next;
    while (node != L) {
        printf("%d",node->data); 
        node=node->next;
    }
    printf("NULL\n");
}



int main(){
    Node* L=InitzaLink();
    headInsert(L,  1);
    headInsert(L,  2);
    headInsert(L,  3);
    headInsert(L,  4);
    tailInsert(L,5);
    delNode(L,4);
    printfList(L);
    return 0;
}
