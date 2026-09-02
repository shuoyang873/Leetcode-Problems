/*
240. 搜索二维矩阵 II
尝试过
中等
相关标签
premium lock icon
相关企业
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
 

示例 1：


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
示例 2：


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
每行的所有元素从左到右升序排列
每列的所有元素从上到下升序排列
-109 <= target <= 109
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,l;
    bool find_target(vector<vector<int>>&matrix,int x,int y,int target){
        if(matrix[x][y]==target)return true;
        else if(matrix[x][y]>target)return false;
        int row[2]={0,1};
        int col[2]={1,0};
        int next_x,next_y;
        for(int i=0;i<2;i++){
            next_x=x+row[i];
            next_y=y+col[i];
            if(next_x<0||next_x>=n||next_y<0||next_y>=l){
                continue;
            }
            if(find_target(matrix,next_x,next_y,target)){
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {        //我采用了递归查找的方法，但是最后会有一两个测试点时间超时
        n=matrix.size(),l=matrix[0].size();
        if(n==0||matrix[0][0]>target)return false;
        return find_target(matrix,0,0,target);
    }
};