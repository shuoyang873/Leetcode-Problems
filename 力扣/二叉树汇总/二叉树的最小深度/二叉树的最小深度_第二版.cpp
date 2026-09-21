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
    int minDepth(TreeNode* root) {          //这一版采用广度优先搜索来写
        if(root==nullptr){            //先特别处理头节点为空的特殊情况
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){     //接着处理只有一个结点的情况
            return 1;
        }
        int n=0;
        queue<TreeNode*>q;
        q.push(root);                //记得要先将头节点放进队列
        while(!q.empty()){
            n++;
            int sz=q.size();
            while(sz>0){
                TreeNode*node=q.front();             //记住，队列的开头的元素是front，不是top，top是stack用的
                if(node->left==nullptr&&node->right==nullptr){      //因为是每层进行遍历的，所以如果在该层有出现有结点的left和right结点都是空，那么说明已经到了最小的深度了，直接返回当前的层数
                    return n;
                }
                if(node->left){                  //如果还没有碰到这种情况，那么先将结点的左节点和右节点放入队列里面
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();             //记得要把开头的结点推出队列，同时该层的数量要减小
                sz--;
            }
        }
        return n;
    }
};