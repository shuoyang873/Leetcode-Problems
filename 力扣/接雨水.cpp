/*
42. 接雨水
已解答
困难
相关标签
premium lock icon
相关企业
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {           //这道题采用动态规划，分别记录该位置左侧最高值，右侧最高值，然后选择较小值，得到该位置所能盛水的最大值
        int n=height.size();
        vector<int>left_max(n);
        vector<int>right_max(n);
        left_max[0]=height[0],right_max[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left_max[i]=max(height[i],left_max[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right_max[i]=max(height[i],right_max[i+1]);
        }
        long long total=0;
        for(int i=0;i<n;i++){
            total+=min(left_max[i],right_max[i])-height[i];
        }
        return total;
    }
};