/*
200. 岛屿数量
已解答
中等
相关标签
premium lock icon
相关企业
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]
输出：1
示例 2：

输入：grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
*/



//这道题的第一个思路是采用深度优先搜索，把每个方格进行遍历，如果是1，那么说明当前的位置是岛屿，接着把当前位置的‘1’改为‘0’，防止以后重复遍历，然后继续向该位置的其他四个方向进行遍历



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int nr,nl;
    void island_count(vector<vector<char>>&grid,int x,int y){
        if(grid[x][y]=='0'){
            return ;              //如果递归到‘0’，说明已经到达岛屿边缘，直接返回
        }
        grid[x][y]='0';                     //将当前位置的‘1’改为‘0’


        //接着向该位置的其他四个方向进行遍历
        if(x-1>=0&&grid[x-1][y]=='1'){
            island_count(grid,x-1,y);
        }
        if(x+1<nr&&grid[x+1][y]=='1'){
            island_count(grid,x+1,y);
        }
        if(y-1>=0&&grid[x][y-1]=='1'){
            island_count(grid,x,y-1);
        }
        if(y+1<nl&&grid[x][y+1]=='1'){
            island_count(grid,x,y+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        nr=grid.size();
        nl=grid[0].size();        //记录二维vector的行数和列数，防止越界
        if(nr==0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<nr;i++){
            for(int j=0;j<nl;j++){
                if(grid[i][j]=='1'){
                    island_count(grid,i,j);       //从头开始遍历，如果遇到‘1’，那么说明当前是岛屿，然后就要深度优先搜索，把所有连接的‘1’都遍历一遍，然后把这些‘1’都改为‘0’
                    ans++;                 //将最后的答案+1
                }
            }
        }
        return ans;             //最后返回答案ans
    }
};