/*
215. 数组中的第K个最大元素
已解答
中等
相关标签
premium lock icon
相关企业
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

示例 1:

输入: [3,2,1,5,6,4], k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
 

提示：

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void qsort(vector<int>&nums,int l,int r){
        if(l>=r)return ;
        int mid=l+(r-l)/2;
        int i=l-1,j=r+1,x=nums[mid];
        while(i<j){
            do{
                i++;
            }while(nums[i]>x);
            do{
                j--;
            }while(nums[j]<x);
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        qsort(nums,l,j);
        qsort(nums,j+1,r);
    }
    int findKthLargest(vector<int>& nums, int k) {           //这版采用快速排序
        int n=nums.size();
        qsort(nums,0,n-1);
        return nums[k-1];
    }
};