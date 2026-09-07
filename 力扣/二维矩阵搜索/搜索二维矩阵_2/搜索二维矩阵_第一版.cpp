/*
74. 搜索二维矩阵
尝试过
中等
相关标签
premium lock icon
相关企业
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

你必须编写一个时间复杂度为 O(log(m * n)) 的解决方案。

 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {          //第一次尝试用二分查找，但是不符合时间复杂度的要求
        int n=matrix.size();
        for(int i=0;i<n;i++){
            auto it=lower_bound(matrix[i].begin(),matrix[i].end(),target);
            if(it!=matrix[i].end()&&*it==target){
                return true;
            }
        }
        return false;
    }
};