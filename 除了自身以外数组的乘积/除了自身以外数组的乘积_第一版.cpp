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
    vector<int> productExceptSelf(vector<int>& nums) {           //这个用到的是数组的连续乘积，就跟用到数组的连续和一样，可以用前缀乘积数组来解决
        int n=nums.size();
        vector<int>ans(n);
        vector<int>left(n);
        vector<int>right(n);
        left[0]=right[n-1]=1;                                   //左右前缀乘积的数组的边界都设定为1
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];                        //得到左侧连续乘积数组
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];                      //得到右侧连续乘积数组
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];                            //最后答案等于该位置的左侧前缀乘积和右侧连续乘积的乘积
        }
        return ans;
    }
};