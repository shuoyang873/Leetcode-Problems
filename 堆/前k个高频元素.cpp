/*
347. 前 K 个高频元素
已解答
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1：

输入：nums = [1,1,1,2,2,3], k = 2

输出：[1,2]

示例 2：

输入：nums = [1], k = 1

输出：[1]

示例 3：

输入：nums = [1,2,1,2,1,2,3,1,3,2], k = 2

输出：[1,2]

 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;           //这边采用哈希表来计数
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        auto cmp=[](const pair<int,int>&a,const pair<int,int>&b)->bool{return a.second>b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>q(cmp);    //这边优先队列里面存储的是数字和对应的出现次数，排序是按照频率从低到高排序
        int sz=0;
        for(const auto& item:mp){
            int num=item.first;
            int cnt=item.second;
            if(sz<k){
                q.push({num,cnt});         //如果当前队列里面的元素个数还少于k个，那么直接把当前数据存入q中
                sz++;
            }
            else{
                //q中已有k个元素
                if(cnt<q.top().second){        //如果当前数字的频率少于堆顶的数字的频率，则直接跳过
                    continue;
                }
                else{
                    q.pop();                 //大于当前堆顶的数字的频率，那么将堆顶的数字弹出，压入当前数字
                    q.push({num,cnt});
                }
            }
        }
        vector<int>vc;
        for(int i=0;i<k;i++){
            vc.push_back(q.top().first);        //遍历q，将答案存入vector中
            q.pop();
        }
        return vc;
    }
};