/*
56. 合并区间
已解答
中等
相关标签
premium lock icon
相关企业
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
示例 3：

输入：intervals = [[4,7],[1,4]]
输出：[[1,7]]
解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。
 

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void qsort(vector<vector<int>>&intervals,int l,int r){
        if(l>=r)return ;         //快速排序的这个递归要注意，开头要写递归出口，就是l>=r,要return
        int mid=l+(r-l)/2;
        int x=intervals[mid][0],i=l-1,j=r+1;       //注意这里要设置一个变量x来记录mid的值，然后要设置i，j这两个变量来记录左右边界，防止在处理过程中左右边界被改变
        while(i<j){
            do{
                i++;
            }while(intervals[i][0]<x);         //注意这里要用do-while的循环
            do{
                j--;
            }while(intervals[j][0]>x);
            if(i<j){                            //这边交换的条件是i<j
                swap(intervals[i],intervals[j]);
            }
        }
        qsort(intervals,l,j);                  //这边进行递归的右边界是j，下面的那个递归是j+1
        qsort(intervals,j+1,r);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {        //这题的思路是参考贪心算法的活动选择这个思路
        int n=intervals.size();
        if(n==0||n==1)return intervals;
        vector<vector<int>>ans;
        qsort(intervals,0,n-1);                            //这边采用快速排序，按照开头start的大小来排序
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){                      //如果当前数据的start<=end，说明这两个区间有重合，可以合并
                if(end<=intervals[i][1]){
                    end=intervals[i][1];                     //同时要特殊处理一下，防止end的值大于当前数据的结尾数字，导致更新出错
                }
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];          //这里要同时更新start和end
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});             //最后一组数据还要手动push_back，防止遗漏
        return ans;
    }
};

//如：解答错误
// 79 / 172 个通过的测试用例
// 提交于 2026.09.02 11:11

// 分析

// 官方题解
// 输入
// intervals =
// [[1,4],[2,3]]

// 添加到测试用例
// 输出
// [[2,4]]
// 预期结果
// [[1,4]]