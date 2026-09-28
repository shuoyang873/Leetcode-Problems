/*
160. 相交链表
已解答
简单
相关标签
premium lock icon
相关企业
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

图示两个链表在节点 c1 开始相交：



题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

自定义评测：

评测系统 的输入如下（你设计的程序 不适用 此输入）：

intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
listA - 第一个链表
listB - 第二个链表
skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 视作正确答案 。
*/


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;          //链表题，开头先判断是否是空节点
        ListNode*pos1=headA,*pos2=headB;                //两个节点开始遍历，如果一个指针到了null，就转移到另外一条链表上继续遍历，最终这两个指针走过的节点数相同，结果有两种可能，1、共同停留在相同的相交节点上，2、没有相交节点，那么都停留在null上
        while(pos1!=pos2){
            pos1=pos1->next;                       //先移动指针，后面再判断是否是null，是否需要转移到另一条链表的头节点上
            pos2=pos2->next;
            if(pos1==NULL&&pos2==NULL)return NULL;         //这里需要判定是否都停留在null上，防止陷入死循环
            if(pos1==NULL)pos1=headB;
            if(pos2==NULL)pos2=headA;
        }
        return pos1;                 //最终两个指针会停留在相同的节点上
    }
};