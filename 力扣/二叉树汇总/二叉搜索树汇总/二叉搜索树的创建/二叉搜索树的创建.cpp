/*
108. 将有序数组转换为二叉搜索树
已解答
简单
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

 

示例 1：


输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

示例 2：


输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 

提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 按 严格递增 顺序排列
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums,0,nums.size()-1);
    }

    TreeNode* build_tree(vector<int>&nums,int l,int r){        //这道题的树的建立要按照中间值来分隔
        if(l>r)return nullptr;                      //注意，这里不能有等号，不然会错过l==r的那一个数，使树不完整
        int mid=l+(r-l)/2;
        TreeNode*node=new TreeNode(nums[mid]);
        node->left=build_tree(nums,l,mid-1);          //这边这个是重点，就是r边界要改为mid-1，不可以包含mid了，因为mid这个数在该递归层中已经被创建结点了，所以不能重复创建
        node->right=build_tree(nums,mid+1,r);
        return node;                              //注意这边因为不是void，所以要返回node这个结点，方便回溯的时候连接结点
    }
};