/*
148. 排序链表
已解答
中等
相关标签
premium lock icon
相关企业
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
 

进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode{
    int val;
    ListNode*next;
};

class Solution {
public:
    static bool range(ListNode*a,ListNode*b){
        return a->val<b->val;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        vector<ListNode*>vec;                              //直接把节点存储到vector里面，直接重新连接节点的顺序
        ListNode*pos=head;
        while(pos!=nullptr){
            vec.push_back(pos);
            pos=pos->next;
        }
        sort(vec.begin(),vec.end(),range);
        int n=vec.size();
        for(int i=0;i<n-1;i++){
            vec[i]->next=vec[i+1];
        }
        vec[n-1]->next=nullptr;
        return vec[0];
    }
};