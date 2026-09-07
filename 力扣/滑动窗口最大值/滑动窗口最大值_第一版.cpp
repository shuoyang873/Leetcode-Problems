/*
239. 滑动窗口最大值
已解答
困难
相关标签
premium lock icon
相关企业
提示
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        //这边采用优先队列的方式来写
        int n=nums.size();
        priority_queue<pair<int,int>>pq;                  //这个优先队列有两个量，第一个存储数值，第二个存储该数值的下标，方便判断是否在当前的滑动窗口里面
        vector<int>ans;
        for(int i=0;i<k;i++){                      //先处理前k个数字，都先存入优先队列里面
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);             //将开头的最大值存入ans数组里面
        for(int i=k;i<n;i++){                      //接着开始解决后面每个滑动窗口
            pq.push({nums[i],i});                  //先把当前位置的数字存入优先队列里面
            while(pq.top().second<=i-k){           //判断当前优先队列的第一个数字是否位于当前滑动窗口内，如果没有，那么弹出，直到第一个数字存在于滑动窗口内
                pq.pop();
            }
            ans.push_back(pq.top().first);         //将当前滑动窗口内的最大值存入ans数组里面
        }
        return ans;
    }
};