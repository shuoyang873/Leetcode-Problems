/*
130. 被围绕的区域
已解答
中等
相关标签
premium lock icon
相关企业
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：

连接：一个单元格与水平或垂直方向上相邻的单元格连接。
区域：连接所有 'O' 的单元格来形成一个区域。
围绕：如果一个区域中的所有 'O' 单元格都不在棋盘的边缘，则该区域被包围。这样的区域 完全 被 'X' 单元格包围。
通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。

 

示例 1：

输入：board = [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]

输出：[['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']]

解释：


在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。

示例 2：

输入：board = [['X']]

输出：[['X']]

 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r,c;
    void dfs(vector<vector<char>>&board,int x,int y){
        if(x<0||x>=r||y<0||y>=c||board[x][y]!='O'){
            return ;
        }
        board[x][y]='A';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
    void solve(vector<vector<char>>& board) {
        r=board.size(),c=board[0].size();
        for(int i=0;i<c;i++){
            dfs(board,0,i);
            dfs(board,r-1,i);
        }
        for(int i=1;i<r-1;i++){
            dfs(board,i,0);
            dfs(board,i,c-1);
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
        return ;
    }
};