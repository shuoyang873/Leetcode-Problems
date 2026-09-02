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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {            //我尝试用单调栈来写，测试样例过了，但是提交有的测试点是错的，说明这个方法不行
        int n=nums.size();
        vector<int>ans;
        stack<pair<int,int>>stk;
        for(int i=0;i<k;i++){
            if(stk.empty()){
                stk.push({nums[i],i});
            }
            else{
                if(nums[i]>stk.top().first){
                    stk.push({nums[i],i});
                }
                else{
                    continue;
                }
            }
        }
        ans.push_back(stk.top().first);
        for(int i=k;i<n;i++){
            while(!stk.empty()&&(stk.top().second<=i-k||stk.top().first<nums[i])){
                stk.pop();
            }
            if(stk.empty()){
                stk.push({nums[i],i});
            }
            else if(stk.top().first<nums[i]){
                stk.push({nums[i],i});
            }
            ans.push_back(stk.top().first);
        }
        return ans;
    }
};


/*
输入
nums =
[1,3,1,2,0,5]
k =
3

添加到测试用例
输出
[3,3,0,5]
预期结果
[3,3,2,5]
*/