/*
4. 寻找两个正序数组的中位数
已解答
困难
相关标签
premium lock icon
相关企业
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 

 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    int get_kth_num(vector<int>&nums1,vector<int>&nums2,int k){
        int index1=0,index2=0;
        while(true){     //?
            if(index1==n){
                return nums2[index2+k-1];
            }
            if(index2==m){
                return nums1[index1+k-1];
            }
            if(k==1){
                return min(nums1[index1],nums2[index2]);
            }

            int newindex1=min(index1+k/2-1,n-1);
            int newindex2=min(index2+k/2-1,m-1);
            int pivot1=nums1[newindex1],pivot2=nums2[newindex2];
            if(pivot1<=pivot2){
                k-=newindex1-index1+1;
                index1=newindex1+1;
            }
            else{
                k-=newindex2-index2+1;
                index2=newindex2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size(),m=nums2.size();
        int total_len=n+m;
        if(total_len%2==1){
            return get_kth_num(nums1,nums2,(total_len+1)/2);
        }
        else{
            return (get_kth_num(nums1,nums2,total_len/2)+get_kth_num(nums1,nums2,total_len/2+1))/2.0;
        }
    }
};