/*
169. 多数元素
已解答
简单
相关标签
premium lock icon
相关企业
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2
 

提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
输入保证数组中一定有一个多数元素。
 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {           //这个解法是使用哈希表
        int n=nums.size();
        unordered_map<int,int>mp;
        int target=n/2,ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>target){
                ans=nums[i];                     //如果已经有数字的数量大于n/2,那么直接退出循环，然后返回答案
                break;
            }
        }
        return ans;
    }
};