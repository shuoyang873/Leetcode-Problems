/*
73. 矩阵置零
已解答
中等
相关标签
premium lock icon
相关企业
提示
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

 

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：


输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

提示：

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int r,h;
    void set_zero(vector<vector<int>>&matrix,int x,int y){
        for(int i=0;i<r;i++){
            matrix[i][y]=0;
        }
        for(int i=0;i<h;i++){
            matrix[x][i]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>coordinate;           //先用一个pair数组存储每个0的位置，然后后面根据这个坐标来把矩阵置零
        r=matrix.size(),h=matrix[0].size();
        if(h==0)return;
        for(int i=0;i<r;i++){
            for(int j=0;j<h;j++){
                if(matrix[i][j]==0){
                    coordinate.push_back({i,j});
                }
            }
        }
        for(int i=0;i<coordinate.size();i++){
            set_zero(matrix,coordinate[i].first,coordinate[i].second);
        }
    }
};