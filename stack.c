//
//  stack.c
//  data_struct
//
//  Created by 梁梁斯宇 on 2018/11/4.
//  Copyright © 2018年 梁斯宇. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>
#define MAX 100;

typedef struct Stack{
    int* base;
    int* top;
    int size;
}Stack;

void initStack(Stack* s){
    s->base = (int*)malloc(100*sizeof(int));
    s->top = s->base;
}

void push(Stack* s, int data){
    s->top ++;
    *s->top = data;
    printf("%d\n", *(s->top));
}

void pop(Stack*s){
    int res = *s->top;
    s->top -- ;
    printf("%d\n", res);
}

void stack(){
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    pop(&stack);pop(&stack);pop(&stack);
}
