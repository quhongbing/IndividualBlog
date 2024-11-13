#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* initLinkList(){
    Node* init_node=(Node*)malloc(sizeof(Node));
    init_node->data=0;
    init_node->next=NULL;
    return init_node;
};

void headInsert(Node* head_node,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->next=head_node->next;             //将头节点的Next*赋给新建Node->next
    node->data=data;                        //
    head_node->next=node;                   //把头节点的Next*指向当前的新建的节点
    head_node->data++;                      //
};

void tailInsert(Node* head_node,int data){
    Node* head=head_node;
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    head_node=head_node->next;
    while (head_node->next)                 //将Next指向NULL的指针指向这个代码段新建的节点Node
    {                                       //然后把该新建的节点Next指针指向NULL
        head_node=head_node->next;          //Node是按指针指向排序的(猜测是堆栈)
    }                                       //
    head_node->next=node;                   //可以假象头节点(head_node)始终在整个单链表的头部(即单链表的最左侧)
    head->data++;
}

void Delete(Node* head_node,int data){
    Node* current = head_node->next;        //设头节点为n,则当前节点current为n-1
    Node* pre_node= head_node;              //
    while (current){                        //
        if (current->data==data){           //若当前数据是要删除的数据时,就将当前数据的Node的Next*赋给前一个Node的Next*
           pre_node->next=current->next;    //即当Node n-1 是要被删除的,那么将Node n->next指向Node n-2
           free(current);
           break;
        }
        pre_node=current;
        current=current->next;
    }
    
}



void printList(Node* input_list){
    input_list=input_list->next;            //将第一个Node拿出来,因为头节点不打印
    while (input_list)
    {
        printf("%d",input_list->data);
        input_list=input_list->next;
    }
    printf("\n");
}

int main(){
    Node* List=initLinkList();
    headInsert(List,1);
    headInsert(List,2);
    tailInsert(List,3);
    tailInsert(List,4);
    Delete(List,3);
    printList(List);
    return 0;
}
