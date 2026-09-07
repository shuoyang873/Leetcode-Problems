/*
199. 二叉树的右视图
已解答
中等
相关标签
premium lock icon
相关企业
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

示例 1：

输入：root = [1,2,3,null,5,null,4]

输出：[1,3,4]

解释：



示例 2：

输入：root = [1,2,3,4,null,null,null,5]

输出：[1,3,4,5]

解释：



示例 3：

输入：root = [1,null,3]

输出：[1,3]

示例 4：

输入：root = []

输出：[]

 

提示:

二叉树的节点个数的范围是 [0,100]
-100 <= Node.val <= 100 
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
    vector<int> rightSideView(TreeNode* root) {            //这道题采用广度优先搜索，跟层序遍历代码基本差不多
        if(root==nullptr)return {};                        //二叉树要特判头节点是否是空！！！！！
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz>0){
                TreeNode*node=q.front();
                q.pop();
                if(sz==1){
                    ans.push_back(node->val);
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sz--;
            }
        }
        return ans;
    }
};