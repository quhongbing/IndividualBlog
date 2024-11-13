/*************************************************************************
	> File Name: test.c
	> Author: quhongbin
	> Mail: 2818777520@qq.com 
	> Created Time: Tue Oct 15 16:12:18 2024
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void f(int **p){
    **p=2;
    *p=(int*)malloc(sizeof(int));
    **p=3;
    printf("%d\n",**p);
}

int main(){
    int a =1;
    int *b =&a;
    f(&b);
    printf("%d %d",a,a);
}
