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
    ListNode* partition(ListNode* head, int x) {            //这道题我看到不需要保留相对位置，就直接采用存入vector里面并排序的方式，直接得到答案
        ListNode*pos=head;
        if(head==nullptr||head->next==nullptr)return head;
        vector<ListNode*>vc;
        while(pos!=nullptr){
            vc.push_back(pos);
            pos=pos->next;
        }
        sort(vc.begin(),vc.end(),[](const ListNode*a,const ListNode*b){return a->val<b->val;});
        for(int i=0;i<vc.size()-1;i++){
            vc[i]->next=vc[i+1];
        }
        vc[vc.size()-1]->next=nullptr;
        return vc[0];
    }
};