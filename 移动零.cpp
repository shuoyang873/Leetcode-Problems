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
        vector<int>vc;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                vc.push_back(nums[i]);         //先遍历一遍数组，因为只有一次循环，而且数据量大小在1e4之内，所以可以直接遍历，不会超时，如果是非0的数字，直接放入vc里面
            }
            else{
                cnt++;        //如果是0，那么先记录数量
            }
        }
        for(int i=0;i<cnt;i++){
            vc.push_back(0);       //最后统一处理0，将cnt个0一起放入vc中
        }
        swap(vc,nums);          //最后记得要交换vc和nums两个vector的数据
    }
};