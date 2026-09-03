/*
46. 全排列
已解答
中等
相关标签
premium lock icon
相关企业
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void dfs(vector<int>&path,int cnt,vector<int>&nums,vector<bool>&visited){
        if(cnt==n){
            ans.push_back(path);
            return ;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                path.push_back(nums[i]);
                visited[i]=true;
                dfs(path,cnt+1,nums,visited);
                visited[i]=false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<bool>visited(n,false);
        vector<int>path;
        dfs(path,0,nums,visited);
        return ans;
    }
};