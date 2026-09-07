/*
53. 最大子数组和
已解答
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {            //这道题求的是连续子数组的最大和，因为符合连续和求最大值，可以使用动态规划，我原本第一次想的是采用双指针，但是结果是错的
        int n=nums.size();
        vector<long long>vc(n+1);        //转成long long，防止后面的数据类型对应不上，会出错
        for(int i=0;i<n;i++){
            vc[i+1]=nums[i];              //让每个数据都往后移动一位，方便后面处理数据
        }
        vector<long long>dp(n+1);         //创建动态规划数组
        dp[1]=vc[1];
        for(int i=1;i<=n;i++){
            dp[i]=max(dp[i-1]+vc[i],vc[i]);           //动态规划的思路是是否带上前面的包袱，如果前面之和是正数，那么带上可以使总和更大，如果前面是负数，那么带上的话会让总和更小，所以不带上

            //也就是计算以第i个节点结尾的数组的最大子数组和是多少
        }
        long long max_n=-1e9;
        for(int i=1;i<=n;i++){
            if(max_n<dp[i])max_n=dp[i];        //遍历，寻找最大值
        }
        return max_n;
    }
};