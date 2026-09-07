/*
15. 三数之和
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
 

提示：

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {             //这边将三数之和转化为两数之和要等于第一个数的负数，并且采用快慢指针的写法
        vector<vector<int>>ans;               //声明一个vector用来存储答案
        int n=nums.size();
        if(n==0)return {};                    //如果n==0，返回空数组
        sort(nums.begin(),nums.end());         //将数组排序
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;        //如果第一个数字有重复，那么直接跳过，防止出现重复答案
            int target=-nums[i];              //target记录接下来两个数组之和要等于target
            int l=i+1,r=n-1;                    //设计双指针，左侧指针位置是i+1,右侧指针是n-1
            while(l<r){                        //双指针的循环终止条件就是两侧指针不可交叉，左侧指针必须在右侧指针的左侧
                if(nums[l]+nums[r]==target){           //如果等于target，那么说明得到了答案
                    ans.push_back({nums[i],nums[l],nums[r]});         //将答案存入ans数组
                    l++;                          //存完之后记得要移动指针
                    r--;                          //这个双指针比较，得到答案之后，先移动指针，然后再比较
                    while(l<r&&nums[l]==nums[l-1])l++;        //同时要用一个循环，判断当前的数字是否等于刚才的数字，防止出现重复答案
                    while(l<r&&nums[r]==nums[r+1])r--;           //循环的条件仍然是l<r
                }                                   
                //双指针的题目，必须要保证左指针一直都在右指针的左侧，所以循环时必须加上这个条件判断l<r
                
                else if(nums[l]+nums[r]<target){
                    l++;                              //如果两数之和小于target，那么说明数字过小，那么就要让左指针向右移动，增大数值
                }
                else if(nums[l]+nums[r]>target){
                    r--;                           //反之，过大，让右侧指针向左移动
                }
            }
        }
        return ans;                     //最后返回答案数组
    }
};