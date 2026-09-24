#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define ERROR -1
#define FULL -2
#define EMP -3
#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
}SeqStack;

int init_stack(SeqStack* s){
    if(s==NULL)return ERROR;
    s->top=-1;
    return OK;
}

int is_empty(SeqStack*s){
    if(s==NULL){
        return ERROR;
    }
    return s->top==-1;
}

int is_full(SeqStack*s){
    if(s==NULL)return ERROR;
    return s->top==STACK_SIZE-1;
}

int push(SeqStack*s,int v){
    if(s==NULL)return ERROR;
    if(is_full(s))return FULL;
    s->top++;
    s->data[s->top]=v;
    return OK;
}

int pop(SeqStack*s,int *v){
    if(s==NULL||v==NULL)return ERROR;
    *v=s->data[s->top];
    s->top--;
    return OK;
}

int get_top(SeqStack*s,int *v){
    if(s==NULL||v==NULL)return ERROR;
    *v=s->data[s->top];
    return OK;
}

int main(){
    SeqStack s;
    
    printf("\n==========1、初始化==========\n");
    init_stack(&s);

    printf("\n==========2、入栈==========\n");
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);

    printf("\n==========3、判空==========\n");
    printf("是否为空：%d\n",is_empty(&s));

    printf("\n==========4、取出元素==========\n");
    int value;
    pop(&s,&value);
    printf("结果是：%d\n",value);
    pop(&s,&value);
    printf("结果是：%d\n",value);
    pop(&s,&value);
    printf("结果是：%d\n",value);
    pop(&s,&value);
    printf("结果是：%d\n",value);

    return 0;
}