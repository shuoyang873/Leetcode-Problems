/*
152. 乘积最大子数组
尝试过
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

请注意，一个只包含一个元素的数组的乘积是这个元素的值。

 

示例 1:

输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 

提示:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
nums 的任何子数组的乘积都 保证 是一个 32-位 整数
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long max(long long a,long long b){
    if(a>b)return a;
    return b;
}

long long min(long long a,long long b){
    if(a<b)return a;
    return b;
}

int maxProduct(int* nums, int numsSize) {
    long long max_num=nums[0],min_num=nums[0],ans=nums[0];         //这边的最大值，最小值，最终答案都先初始化为nums[0]
    //这边的max_num,min_num表示到当前位置，能够得到的连续的最大的乘积和最小的乘积，他们不一定有相同的起点
    for(int i=1;i<numsSize;i++){
        int mx=max_num,mn=min_num;     //这个mx和mn的使用是重点，我第二次写的时候一开始觉得这个东西没用！！！！！！！
        //这边要先将max_num,min_num都先存起来，防止后面max_num，min_num发生改变，无法用原本的值来计算，会导致答案出错
        max_num=max(mx*nums[i],max((long long)nums[i],mn*nums[i]));    //这边采用两层max嵌套，分为两种情况，选择连接在前面的数据的后面和不选择连接在前面的数据的后面，将所有结果进行比较得到最大值，如果选择连接在前面的数据的后面，那么最大值可能是由当前的最大值乘上他，或者是最小值乘上他；如果不选，那么就是当前的数据
        min_num=min(mx*nums[i],min((long long)nums[i],mn*nums[i]));    //同理得到最小值
        ans=max(max_num,ans);         //对ans进行更新，让他始终是当前的最大值
    }
    return ans;
}