/*
124. 二叉树中的最大路径和
已解答
困难
相关标签
premium lock icon
相关企业
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

 

示例 1：


输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
示例 2：


输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 

提示：

树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000
 
面试中遇到过这道题?
1/5
是
否
通过次数
785,471/1.6M
通过率
48.4%
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
    int max_sum=-1e9;
    int find_max_path_sum(TreeNode*root,int sum){
        if(root==nullptr)return 0;
        int left_sum=max(find_max_path_sum(root->left,sum),0);
        int right_sum=max(find_max_path_sum(root->right,sum),0);
        int priceNewpath=root->val+left_sum+right_sum;
        max_sum=max(priceNewpath,max_sum);
        return root->val+max(left_sum,right_sum);
    }
    int maxPathSum(TreeNode* root) {
        find_max_path_sum(root,0);
        return max_sum;
    }
};