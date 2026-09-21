/*
111. 二叉树的最小深度
已解答
简单
相关标签
premium lock icon
相关企业
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 

提示：

树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
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
    int dfs(TreeNode*root){
        if(root==nullptr){        //如果一开始的头节点就是空节点，那么就返回0
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){      //如果当前结点是叶子节点，那么说明已经到了底部，返回1
            return 1;
        }
        int len_l,len_r;
        //下面这个左右结点判空一定要加，防止出现一条单侧链的情况，那样会得到1
        if(root->left)len_l=dfs(root->left);             //这边是计算左侧子树的最小深度
        if(root->right)len_r=dfs(root->right);           //这边是计算右侧子树的最小深度
        return min(len_l,len_r)+1;                     //取二者的较小值，并+1
    }
    int minDepth(TreeNode* root) {           //这边采用深度优先搜索的方法来写
        return dfs(root);
    }
};