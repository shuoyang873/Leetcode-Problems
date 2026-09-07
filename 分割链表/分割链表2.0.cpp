/*
面试题 02.04. 分割链表
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你不需要 保留 每个分区中各节点的初始相对位置。

 

示例 1：


输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]
 

提示：

链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {            //采用两条链表分别连接
        if(head==nullptr||head->next==nullptr)return head;
        ListNode*small_head=new ListNode,*small_tail=small_head;
        ListNode*big_head=new ListNode,*big_tail=big_head;
        ListNode*pos=head;
        while(pos!=nullptr){
            ListNode*nt=pos->next;
            if(pos->val<x){
                small_tail->next=pos;
                small_tail=pos;
                pos=nt;
            }
            else{
                big_tail->next=pos;
                big_tail=pos;
                pos=nt;
            }
        }
        big_tail->next=nullptr;
        ListNode*tmp=big_head;
        big_head=big_head->next;
        delete tmp;
        small_tail->next=big_head;
        ListNode*newhead=small_head->next;
        delete small_head;
        return newhead;
        
    }
};