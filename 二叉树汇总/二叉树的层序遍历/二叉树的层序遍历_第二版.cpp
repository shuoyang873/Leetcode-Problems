/*
102. 二叉树的层序遍历
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目在范围 [0, 2000] 内
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
    vector<vector<int>> levelOrder(TreeNode* root) {           //这边我采用队列和广度优先搜索来做这道题，第二次改进，代码更加简洁
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            ans.push_back(vector<int>());                    //此处没有另外声明新的vector变量，直接在ans后面push_back，然后直接往里面放该层的数据
            while(sz>0){
                TreeNode*node=q.front();
                q.pop();
                ans.back().push_back(node->val);             //将该层的数据放入vector，这样可以避免末尾还要再判断一次是否为空
                if(node->left){
                    q.push(node->left);                       //这边记得队列要存入新的节点，不然只遍历完一层之后就停止了
                }
                if(node->right){
                    q.push(node->right);
                }
                sz--;
            }
        }
        return ans;
    }
};