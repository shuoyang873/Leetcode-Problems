#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define ERROR -1
#define FULL -2
#define EMP -3

typedef struct LinkNode{
    int data;
    struct LinkNode*next;
}LinkNode;
typedef LinkNode*LinkStack;

void destroy(LinkStack s){
    if(s==NULL)return ;
    LinkNode*cur=s;
    while(cur!=NULL){
        LinkNode*tmp=cur;
        cur=cur->next;
        free(tmp);
    }
}

LinkStack init(){
    LinkNode*head=(LinkNode*)malloc(sizeof(LinkNode));
    if(head==NULL)return NULL;
    head->data=0;
    head->next=NULL;
    return head;
}

int is_empty(LinkStack s){
    if(s==NULL)return ERROR;
    if(s->next==NULL)return 0;
    return 1;
}

int push(LinkStack s,int data){
    if(s==NULL)return ERROR;
    LinkNode*node=(LinkNode*)malloc(sizeof(LinkNode));
    if(node==NULL)return ERROR;
    node->data=data;
    node->next=s->next;
    s->next=node;
    return OK;
}

int pop(LinkStack s,int *v){
    if(s==NULL||v==NULL||is_empty(s)){
        return ERROR;
    }
    LinkNode*node=s->next;
    *v=node->data;
    s->next=node->next;
    free(node);
    return OK;
}

int get_top(LinkStack s,int *v){
    if(s==NULL||v==NULL||is_empty(s))return ERROR;
    *v=s->next->data;
    return OK;
}

int main(){
    LinkStack s=NULL;

    printf("\n==========1、初始化==========\n");
    s=init();
    if(s==NULL){
        printf("初始化失败\n");
        return 1;
    }

    printf("\n==========2、判空==========\n");
    printf("是否为空：%d\n",is_empty(s));

    printf("\n==========3、入栈==========\n");
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);

    printf("\n==========2、判空==========\n");
    printf("是否为空：%d\n",is_empty(s));

    printf("\n==========4、出栈==========\n");
    int v;
    pop(s,&v);
    printf("出栈结果：%d\n",v);
    pop(s,&v);
    printf("出栈结果：%d\n",v);
    pop(s,&v);
    printf("出栈结果：%d\n",v);
    pop(s,&v);
    printf("出栈结果：%d\n",v);
    
    printf("\n==========2、判空==========\n");
    printf("是否为空：%d\n",is_empty(s));

    destroy(s);
    s=NULL;
    return 0;
}