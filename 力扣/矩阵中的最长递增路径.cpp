/*
LCR 112. 矩阵中的最长递增路径
已解答
困难
相关标签
premium lock icon
相关企业
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

 

示例 1：



输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。
示例 2：



输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
示例 3：

输入：matrix = [[1]]
输出：1
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
 

注意：本题与主站 329 题相同： https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int h,r;
    int find_max_len(vector<vector<int>>&matrix,int x,int y,vector<vector<int>>&cnt){
        if(cnt[x][y]!=0){
            return cnt[x][y];
        }
        int mov_x[4]={0,1,0,-1};
        int mov_y[4]={1,0,-1,0};
        int next_x,next_y;
        cnt[x][y]++;
        for(int i=0;i<4;i++){
            next_x=x+mov_x[i];
            next_y=y+mov_y[i];
            if(next_x>=0&&next_x<h&&next_y>=0&&next_y<r&&matrix[next_x][next_y]>matrix[x][y]){
                cnt[x][y]=max(cnt[x][y],find_max_len(matrix,next_x,next_y,cnt)+1);
            }
        }
        return cnt[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {           //这道题采用记忆化深度优先搜索
        h=matrix.size();
        r=matrix[0].size();
        if(h==0)return 0;
        vector<vector<int>>cnt(h,vector<int>(r,0));          //这边采用一个cnt数组，用来记录已经遍历过的位置的最长序列长度，如果后续遍历到这个位置，直接返回这个位置的数值，这个就是记忆化
        int ans=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<r;j++){
                ans=max(ans,find_max_len(matrix,i,j,cnt));
            }
        }
        return ans;
    }
};