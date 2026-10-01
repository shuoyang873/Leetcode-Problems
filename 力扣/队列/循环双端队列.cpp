/*
641. 设计循环双端队列
已解答
中等
相关标签
premium lock icon
相关企业
设计实现双端队列。

实现 MyCircularDeque 类:

MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
 

示例 1：

输入
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
输出
[null, true, true, true, false, 2, true, true, true, 4]

解释
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
 
 

提示：

1 <= k <= 1000
0 <= value <= 1000
insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull  调用次数不大于 2000 次
*/


#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
private:
    int front;
    int rear;
    int capacity;
    vector<int>que;
public:
    MyCircularDeque(int k) {
        capacity=k+1;                //这边的capacity不要重新声明一个int，不然在这里面初始化的是一个局部变量，初始化的不是全局变量的capacity，这会导致后面出错
        que=vector<int>(capacity);
        front=rear=0;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        front=(front-1+capacity)%capacity;       //这边前端入队的函数有一个注意点，就是要先改变front，然后再将数据入队
        que[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        que[rear]=value;
        rear=(rear+1)%capacity;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        front=(front+1)%capacity;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        rear=(rear-1+capacity)%capacity;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return que[front];              //这边获取开头的数字，就是直接获取下标为front的数据
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return que[(rear-1+capacity)%capacity];
    }
    
    bool isEmpty() {
        return rear==front;
    }
    
    bool isFull() {
        return (rear+1)%capacity==front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */