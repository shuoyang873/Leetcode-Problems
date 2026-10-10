/*
918. 环形子数组的最大和
已解答
中等
相关标签
premium lock icon
相关企业
提示
给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

 

示例 1：

输入：nums = [1,-2,3,-2]
输出：3
解释：从子数组 [3] 得到最大和 3
示例 2：

输入：nums = [5,-3,5]
输出：10
解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
示例 3：

输入：nums = [3,-2,2,-3]
输出：3
解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
 

提示：

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104​​​​​​​
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {     //这边采用前缀和+单调队列来写
    //计算最大子数组和的方法有：1、动态规划，转移方程为dp[i]=max(dp[i-1]+nums[i],nums[i]);2、前缀和相减，可以得到对应区间的和
    //这道题要用前缀和配合单调队列来写是因为这个数组说要循环
        int pre=nums[0],res=nums[0];    //这边的pre用来记录前缀和，res用来记录最大的结果
        deque<pair<int,int>>q;          //这边的双端队列，存储的是下标和对应的前缀和
        //这个双端队列是单调队列，他存储的是当前有效长度内，最小的前缀和，因为用当前的前缀和减去有效长度内最小的前缀和，得到的数据才会尽可能的大
        int n=nums.size();
        q.push_back({0,pre});           //要先将第一个数据先存进去
        for(int i=1;i<2*n;i++){
            while(!q.empty()&&q.front().first<i-n){      //因为这个循环队列的长度不可以超过n，所以要先清除掉已经超出范围的数据！！！！这个是我一开始不知道要如何控制不重复计算的解决方法！！！
                q.pop_front();
            }
            pre+=nums[i%n];           //此处pre加上当前的数字
            res=max(res,pre-q.front().second);           //判断之前的最大数和当前的前缀和减去当前最小的前缀和，得到的结果，哪个数据大
            while(!q.empty()&&q.back().second>=pre){      //更新数据，使队列保持单调，如果当前的前缀和小于队列中的数据，那么要循环弹出，最终将这个更小的前缀和入队
                q.pop_back();
            }
            q.push_back({i,pre});
        }
        return res;
    }
};