/*
283. 移动零
已解答
简单
相关标签
premium lock icon
相关企业
提示
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
 

提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

进阶：你能尽量减少完成的操作次数吗？
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int fast=0,slow=0;       //这个是采用快慢指针的方法
        while(fast<n){
            if(nums[fast]){          //快指针在前面移动，如果遇到非0的数字，那么我们需要进行处理
                swap(nums[fast],nums[slow]);          //交换快指针和慢指针的数字
                slow++;              //移动慢指针
            }
            fast++;                  //移动快指针
        }
    }
};