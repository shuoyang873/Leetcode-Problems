/*

代码
测试用例
测试用例
测试结果
543. 二叉树的直径
已解答
简单
相关标签
premium lock icon
相关企业
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。

 

示例 1：


输入：root = [1,2,3,4,5]
输出：3
解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
示例 2：

输入：root = [1,2]
输出：1
 

提示：

树中节点数目在范围 [1, 104] 内
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
    int max_len=0;
    int find_diameter(TreeNode*root){        //计算每个结点两侧可以得到的最大路径长度
        if(root==nullptr){           //如果当前结点是null，直接返回0
            return 0;
        }
        int len_l=find_diameter(root->left),len_r=find_diameter(root->right);
        int len=len_l+len_r;     //这边计算当前结点两侧可以达到的最大长度
        max_len=max(max_len,len);          //进行比较，更新max_len
        return max(len_l,len_r)+1;    //返回在当前结点可以到达叶节点的最大长度
    }
    int diameterOfBinaryTree(TreeNode* root) {       //我的这个采用递归的写法会在数据很大的时候导致超时，其他情况可以正常运行
        find_diameter(root);
        return max_len;
    }
};