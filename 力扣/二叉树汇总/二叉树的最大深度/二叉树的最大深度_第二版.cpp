/*
104. 二叉树的最大深度
已解答
简单
相关标签
premium lock icon
相关企业
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

 

示例 1：



 

输入：root = [3,9,20,null,null,15,7]
输出：3
示例 2：

输入：root = [1,null,2]
输出：2
 

提示：

树中节点的数量在 [0, 104] 区间内。
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


 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {               //采用广度优先搜索来解决
        if(root==nullptr)return 0;               //对于链表题，第一件要做的事情就是判断头节点是否是空!!!!!!!!!!
        int ans=0;
        queue<TreeNode*>q;                      //这里声明一个专门用来存放TreeNode节点的队列
        q.push(root);                           //先把根节点放入队列中
        while(!q.empty()){                      //如果队列非空，那么说明还有节点需要处理
            int sz=q.size();                    //这边先记录在这一层的节点数，方便后面处理
            while(sz>0){                        //循环处理当前这一层的节点
                                                //这边的sz的循环条件是>0，而不是>=0，否则会越界访问
                TreeNode*node=q.front();        //把当前这一层的节点先记录下来，然后弹出
                q.pop();
                if(node->left)q.push(node->left);         //如果该节点的左节点非空，那么压入队列中
                if(node->right)q.push(node->right);       //同理，处理右节点
                sz--;                           //记得让sz--，防止处理到下一层的节点
            }
            ans++;                              //sz为0说明当前这一层已经处理完，ans要++
        }
        return ans;
    }
};