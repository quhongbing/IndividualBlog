/*************************************************************************
	> File Name: Stack/stack.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Mon Oct 14 19:36:40 2024
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node ;

Node* InitNode(){
    Node* headNode=(Node*)malloc(sizeof(Node));
    headNode->data=0;
    headNode->next=NULL;
    return headNode;
}

void stackPush(Node* S,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if (S->data == 0) {
        node->next=NULL;
        S->next=node;
        S->data ++;
    }else {
        node->next=S->next;
        S->next=node;
        S->data ++;
    }
}

int stackPop(Node* S){
    if (S->data == 0) {
        printf("stack is no elements\n");
        return -1;
    }else {
        Node* currentNode=S->next;
        int valuePop=currentNode->data;
        S->next=currentNode->next;
        free(currentNode);
        S->data --;
        return valuePop;
        //printf("%d",S->next->data);
    }
}

void stackPrint(Node* S){
    Node* currentNode=S->next;
    while (currentNode) {
        printf("%d",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("NULL\n");
}

int main(){
    Node* S=InitNode();
    stackPush(S,1);
    stackPush(S,2);
    stackPush(S,3);
    int temp=stackPop(S);
    printf("%d\n",temp);
    stackPrint(S);
    printf("%d",S->data);
}
