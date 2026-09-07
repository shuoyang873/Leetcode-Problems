/*
238. 除了自身以外数组的乘积
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

 

示例 1:

输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:

输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
 

提示：

2 <= nums.length <= 105
-30 <= nums[i] <= 30
输入 保证 数组 answer[i] 在  32 位 整数范围内
 

进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {      //这边不用两侧的连续乘积数组，而是直接在ans上面直接相乘
        int n=nums.size();
        vector<int>ans(n,1);                    //注意要把ans数组的每个元素都初始化为1，否则默认初始化为0，最终结果都会为0
        int l=1;
        for(int i=0;i<n;i++){                 //先对左侧连续乘积
            ans[i]*=l;
            l*=nums[i];
        }
        int r=1;
        for(int i=n-1;i>=0;i--){                //再对右侧连续乘积
            ans[i]*=r;
            r*=nums[i];
        }
        return ans;
    }
};