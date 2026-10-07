/*
16. 最接近的三数之和
已解答
中等
相关标签
premium lock icon
相关企业
给定一个长度为 n 的整数数组 nums 和 一个整数 target。

请你从 nums 中选出三个在 不同下标位置 的整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在 恰好 一个解。

 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
示例 2：

输入：nums = [0,0,0], target = 1
输出：0
解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
 

提示：

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int best=1e7;

        auto update=[&](int cur){
            if(abs(cur-target)<abs(best-target)){
                best=cur;
            }
        };

        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int left=i+1,right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target)return target;
                update(sum);
                if(sum>target){
                    int next_right=right-1;
                    while(next_right>left&&nums[next_right]==nums[right]){
                        next_right--;
                    }
                    right=next_right;
                }
                else {
                    int next_left=left+1;
                    while(next_left<right&&nums[next_left]==nums[left]){
                        next_left++;
                    }
                    left=next_left;
                }
            }
        }
        return best;
    }
};