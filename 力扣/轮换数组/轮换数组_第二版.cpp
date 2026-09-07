/*
189. 轮转数组
已解答
中等
相关标签
premium lock icon
相关企业
提示
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

 

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
 

提示：

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

进阶：

尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int>&nums,int l,int r){          //直接对数组进行翻转
        while(l<r){
            swap(nums[l],nums[r]);                       //这边直接使用swap函数
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {             //将k个元素转移到数组前面，可以变成先将整个数组翻转，然后将前k个数字翻转，再将后面的数字翻转，即可得到答案
        int n=nums.size();
        int mov=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,mov-1);             //这边记得使用的是mov，而不是原本的k，防止访问溢出
        reverse(nums,mov,n-1);
    }
};