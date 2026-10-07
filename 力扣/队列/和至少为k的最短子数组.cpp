/*
862. 和至少为 K 的最短子数组
已解答
困难
相关标签
premium lock icon
相关企业
给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。

子数组 是数组中 连续 的一部分。

 

示例 1：

输入：nums = [1], k = 1
输出：1
示例 2：

输入：nums = [1,2], k = 4
输出：-1
示例 3：

输入：nums = [2,-1,2], k = 3
输出：3
 

提示：

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        int res=n+1;
        deque<int>qu;
        for(int i=0;i<=n;i++){
            int cur_sum=prefix[i];
            while(!qu.empty()&&cur_sum-prefix[qu.front()]>=k){
                res=min(res,i-qu.front());
                qu.pop_front();
            }
            while(!qu.empty()&&prefix[qu.back()]>=cur_sum){
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res==n+1?-1:res;
    }
};