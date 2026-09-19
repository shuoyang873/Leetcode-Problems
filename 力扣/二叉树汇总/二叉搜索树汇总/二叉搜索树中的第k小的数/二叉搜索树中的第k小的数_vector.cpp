/*
230. 二叉搜索树中第 K 小的元素
已解答
中等
相关标签
premium lock icon
相关企业
提示
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。

 

示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1
示例 2：


输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
 

 

提示：

树中的节点数为 n 。
1 <= k <= n <= 104
0 <= Node.val <= 104
 

进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？
*/


#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void push_TreeNode(vector<TreeNode*>&vc,TreeNode*root){
        if(root==nullptr)return;
        vc.push_back(root);
        if(root->left)push_TreeNode(vc,root->left);
        if(root->right)push_TreeNode(vc,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*>vc;
        push_TreeNode(vc,root);
        sort(vc.begin(),vc.end(),[](const TreeNode*a,const TreeNode*b){return a->val<b->val;});
        return vc[k-1]->val;
    }
};