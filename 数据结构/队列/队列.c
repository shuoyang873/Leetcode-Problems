// #include<stdio.h>
// #include<stdlib.h>

// #define OK 0
// #define ERROR -1
// #define EMP -2
// #define STACK_SIZE 100
// #define FULL -3

// typedef struct Seqstack{
//     int data[STACK_SIZE];
//     int top;
// }Seqstack;

// int init(Seqstack*s){
//     if(s==NULL){
//         return ERROR;
//     }
//     s->top=-1;
//     return OK;
// }

// int is_empty(Seqstack*s){
//     if(s==NULL)return ERROR;
//     return s->top==-1;
// }

// int is_full(Seqstack*s){
//     if(s==NULL)return ERROR;
//     return s->top==STACK_SIZE-1;
// }


// int push(Seqstack*s,int v){
//     if(s==NULL)return ERROR;
//     if(is_full(s)){
//         return FULL;
//     }
//     s->top++;
//     s->data[s->top]=v;
//     return OK;
// }

// int pop(Seqstack*s,int *v){
//     if(s==NULL||v==NULL)return ERROR;
//     if(is_empty(s))return EMP;
//     *v=s->data[s->top];
//     s->top--;
//     return OK;
// }

// int main(){
//     Seqstack s;
//     init(&s);

//     int n,m;
//     printf("请输入：");
//     scanf("%d %d",&n,&m);
//     while(n!=0){
//         push(&s,n%m);
//         n/=m;
//     }
//     while(!is_empty(&s)){
//         int v;
//         pop(&s,&v);
//         printf("%d",v);
//     }
//     return 0;
// }


