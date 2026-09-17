/*
236. 二叉树的最近公共祖先
已解答
中等
相关标签
premium lock icon
相关企业
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

示例 1：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
示例 2：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
示例 3：

输入：root = [1,2], p = 1, q = 2
输出：1
 

提示：

树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。
*/


#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode*ans;             //这边设置一个全局的结点，用来标记公共祖先结点
    bool find_ancestor(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL){
            return false;             //这个要学习一下，我一开始惯性思维，认为应该返回true，但是在这道题中，如果遍历到最终的叶节点，说明没有找到对应的两个结点，所以要返回false，不要想当然返回true
        }
        //对于公共祖先结点，有两种情况，1、两个结点分别位于公共祖先两侧，而两个结点所连接的结点是公共结点2、一个结点位于另外一个结点的一侧，那么该结点就是两个结点的公共祖先
        bool sig_l=find_ancestor(root->left,p,q);      //记录左侧的结点情况
        bool sig_r=find_ancestor(root->right,p,q);     //记录右侧的结点情况
        if((sig_l&&sig_r)||(root==p||root==q)&&(sig_l||sig_r)){       //这个条件判断是重点，如果左侧和右侧的结点判断显示都找到了对应的结点，那么说明当前的结点是公共结点，或者是当前节点和其中一个结点相同，然后在这个结点的其中一侧有找到另外一个结点，那么当前结点就是公共结点
            ans=root;
        }
        return sig_l||sig_r||root==p||root==q;        //这边要返回的是当前结点的左侧结点情况，和右侧结点情况，以及当前结点是否是要找的结点
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {       //这边采用深度优先搜索的方式来查找最近的公共祖先结点
        find_ancestor(root,p,q);
        return ans;
    }
};