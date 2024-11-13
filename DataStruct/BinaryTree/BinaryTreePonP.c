/*************************************************************************
	> File Name: BinaryTreePonP.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Wed Oct 16 20:16:05 2024
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct BiTree{
    char data;
    struct BiTree* leftChild;
    struct BiTree* rightChild;
}BiTree ;

void createTree(BiTree* *T){   //*T本质上是一个地址
    char ch;
    scanf("%c",&ch);
    if (ch == '#') {
       *T=NULL; 
    }else {
        (*T)=(BiTree*)malloc(sizeof(BiTree));
        (*T)->data=ch;
        createTree(&((*T)->leftChild));      //  (*T)->leftChild访问当前地址，结构体中的leftChild.leftChild嵌在头节点里
        createTree(&((*T)->rightChild));
    }
}

void preOrder(BiTree* T){ //为何传入BiTree* T???
    if (T == NULL) {
        return;
    }else {
        printf("%c",T->data);
        preOrder(T->leftChild);
        preOrder(T->rightChild);
    }
}
void inOrder(BiTree* T){
    if (T == NULL) {
        return;
    }else {
        inOrder(T->leftChild);
        printf("%c",T->data);
        inOrder(T->rightChild);
    }
}
void postOrder(BiTree* T){
    if (T == NULL) {
        return;
    }else {
        postOrder(T->leftChild);
        postOrder(T->rightChild);
        printf("%c",T->data);
    }
}
int main(){
    BiTree* T;
    createTree(&T);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
}
