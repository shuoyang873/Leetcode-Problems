/*
225. 用队列实现栈
已解答
简单
相关标签
premium lock icon
相关企业
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 

注意：

你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 

示例：

输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
 

提示：

1 <= x <= 9
最多调用100 次 push、pop、top 和 empty
每次调用 pop 和 top 都保证栈不为空
 

进阶：你能否仅用一个队列来实现栈。
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;



class MyStack {
public:
    queue<int>que1,que2;        //采用两个队列实现栈的结构
    MyStack() {
        
    }
    
    void push(int x) {
        que2.push(x);          //先将输入的数据压进que2队列中
        while(!que1.empty()){           //然后将que1队列中的数据一次输出，压进que2队列中，从而将最后输入的数据放在队列的最下面，实现最先输出的功能
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1,que2);      //最后交换que1，que2的内容，以que1队列为主，que2队列为空
    }
    
    int pop() {
        int ans=que1.front();         //pop的操作要返回值，同时要把数据弹出栈顶，所以要pop的操作
        que1.pop();                   //还有一个注意点就是队列的开头的数据是front，跟top不一样，这个要注意
        return ans;
    }
    
    int top() {
        return que1.front();            //top是直接得到栈顶的数据，不用弹出
    }
    
    bool empty() {
        return que1.empty();            //判断是否是空，直接用empty函数即可
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */