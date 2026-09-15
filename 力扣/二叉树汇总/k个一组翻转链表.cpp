/*
25. K 个一组翻转链表
已解答
困难
相关标签
premium lock icon
相关企业
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：



输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
 

提示：
链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k==1)return head;
        ListNode*slow=head,*fast=head,*newhead=new ListNode,*prev=newhead;
        int cnt=0;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next;
            cnt++;
            if(cnt==k-1){
                ListNode*next=fast->next,*tmp_head=nullptr,*tmp=slow;
                while(cnt>=0){
                    ListNode*tmp_next=tmp->next;
                    tmp->next=tmp_head;
                    tmp_head=tmp;
                    tmp=tmp_next;
                    cnt--;
                }
                prev->next=tmp_head;
                prev=slow;
                slow=next;
                fast=next;
                cnt=0;
            }
        }
        prev->next=slow;
        ListNode*true_head=newhead->next;
        ListNode*tmp=newhead;
        delete tmp;
        return true_head;
    }
};