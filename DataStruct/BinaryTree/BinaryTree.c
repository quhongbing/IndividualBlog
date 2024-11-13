/*************************************************************************
	> File Name: BinaryTree.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Tue Oct 15 15:12:28 2024
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree{
    char data;
    struct BinaryTree* leftChild;
    struct BinaryTree* rightChild;
}BiTree ;

BiTree* createTree(){
    BiTree* T;
    char input;
    scanf("%c",&input);
    if (input == '#') {
        T=NULL;
    }else {
        T=(BiTree*)malloc(sizeof(BiTree));
        T->data=input;
        T->leftChild=createTree();
        T->rightChild=createTree();
    }
    return T;
}

void preOrder(BiTree* T){
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
    BiTree* T=createTree();
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    return 0;
}
