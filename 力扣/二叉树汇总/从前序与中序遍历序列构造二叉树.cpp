/*
105. 从前序与中序遍历序列构造二叉树
已解答
中等
相关标签
premium lock icon
相关企业
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列
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
    unordered_map<int,int>index;
    TreeNode*mybuildtree(vector<int>&preorder,vector<int>&inorder,int pre_l,int pre_r,int in_l,int in_r){
        if(pre_l>pre_r){
            return nullptr;
        }
        int root=preorder[pre_l];
        TreeNode*node=new TreeNode(root);
        int size_left=index[root]-in_l;
        node->left=mybuildtree(preorder,inorder,pre_l+1,pre_l+size_left,in_l,index[root]-1);
        node->right=mybuildtree(preorder,inorder,pre_l+size_left+1,pre_r,index[root]+1,in_r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }
        TreeNode*binary_tree=mybuildtree(preorder,inorder,0,n-1,0,n-1);
        return binary_tree;
    }
};