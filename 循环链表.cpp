/*
LCR 029. 循环有序列表的插入
已解答
中等
相关标签
premium lock icon
相关企业
给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。

 

示例 1：


 

输入：head = [3,4,1], insertVal = 2
输出：[3,4,1,2]
解释：在上图中，有一个包含三个元素的循环有序列表，你获得值为 3 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3 之间，插入之后，整个列表如上图所示，最后返回节点 3 。


示例 2：

输入：head = [], insertVal = 1
输出：[1]
解释：列表为空（给定的节点是 null），创建一个循环有序列表并返回这个节点。
示例 3：

输入：head = [1], insertVal = 0
输出：[1,0]
 

提示：

0 <= Number of Nodes <= 5 * 10^4
-10^6 <= Node.val <= 10^6
-10^6 <= insertVal <= 10^6
 

注意：本题与主站 708 题相同： https://leetcode.cn/problems/insert-into-a-sorted-circular-linked-list/
*/

#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node*newnode=new Node(insertVal);
        if(head==NULL){
            newnode->next=newnode;                //先特殊处理head是空节点的情况，如果是空节点，那么当前的节点要指向自己，然后返回这个节点
            return newnode;
        }
        if(head->next==NULL){
            head->next=newnode;                  //特殊处理只有一个节点的情况，插入任何位置都会成为有序的链表
            newnode->next=head;
            return head;
        }
        Node*cur=head,*nex=head->next;              //这边采用双指针的方式，用来判断insertval是否在前后两个节点的值之间，cur的节点选择head，nex的节点选择head->next
        while(nex!=head){                              //循环终止的条件是nex！=head
            if(insertVal>=cur->val&&insertVal<=nex->val){          //需要插入的情况1、insertval的值介于cur和nex的值之间
                break;          //说明找到要插入的位置，直接break退出循环
            }
            else if(cur->val>nex->val){              //需要插入的情况2、循环到这个链表的最大值和最小值之间，如果比最大值大，或者比最小值小，那么就需要插入
                if(insertVal<nex->val||insertVal>cur->val){      //这个条件判断不可以少，如果少了，就会出现只要碰到最大和最小值之间，就会直接插入，导致错误，因为head可能位于数值的中间区域，后面还会有较小的值需要排查，只有符合条件才可以在这个位置插入
                    break;
                }
            }
            cur=cur->next;          //移动指针，防止陷入死循环
            nex=nex->next;
        }
        cur->next=newnode;          //将insertval的节点插入
        newnode->next=nex;
        return head;
    }
};