/*
152. 乘积最大子数组
尝试过
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

请注意，一个只包含一个元素的数组的乘积是这个元素的值。

 

示例 1:

输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 

提示:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
nums 的任何子数组的乘积都 保证 是一个 32-位 整数
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {           //第一版我采用了暴力解法，思路是以第i个元素为结尾，向前遍历计算数值，结果会有最后一个点运行超时，这种遍历的做法时间复杂度过高
        int n=nums.size();
        long long max_n=-1e9;
        for(int i=0;i<n;i++){
            long long res=1;
            for(int j=i;j>=0;j--){
                res*=nums[j];
                if(res>max_n){
                    max_n=res;
                }
            }
        }
        return max_n;
    }
};