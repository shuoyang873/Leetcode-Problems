/*
622. 设计循环队列
已解答
中等
相关标签
premium lock icon
相关企业
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
 

提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int front=0;
int tail=0;
int capacity=0;
typedef struct {
    int num[100005];
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue*obj=(MyCircularQueue*)malloc(sizeof(MyCircularQueue));    //这边因为函数类型是MyCircularQueue*，所以这边要创建一个MyCircularQueue*这个类型的数据，所以要malloc
    capacity=k+1;       //这边的capacity要设定为k+1！！！！！
    front=0;
    tail=0;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(!obj){
        return false;
    }
    if((tail+1)%capacity==front)return false;
    obj->num[tail]=value;
    tail=(tail+1)%capacity;                    //还有就是数据的名称要一致，不要一会tail，一会rear
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!obj)return false;
    if(front==tail)return false;
    front=(front+1)%capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(!obj)return -1;
    if(tail==front)return -1;                          //还有c语言里面的话，如果要使用函数，如果在前面没有声明或者详细写明，那么会报错，所以这里要判空或者判满，就直接自己写一下就好了
    return obj->num[front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(!obj)return false;
    if(front==tail)return -1;
    return obj->num[(tail-1+capacity)%capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(!obj)return false;
    return front==tail?true:false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(!obj)return false;
    return (tail+1)%capacity==front?true:false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj)return;
    front=tail=0;
    return ;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/