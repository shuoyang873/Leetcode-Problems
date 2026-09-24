/*
994. 腐烂的橘子
已解答
中等
相关标签
premium lock icon
相关企业
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

 

示例 1：



输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
示例 3：

输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] 仅为 0、1 或 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int>q;
        int row=grid.size();
        int col=grid[0].size();
        int total=0;
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    total++;
                }
                if(grid[i][j]==2){
                    q.push(i*col+j);
                }
            }
        }
        if(total==0){
            return 0;
        }
        int next_step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};


        while(!q.empty()){
            int next_row,next_col;
            int sz=q.size();
            while(sz>0){
                int index=q.front();
                cout<<"当前处理位置："<<index<<endl;
                int x=index/col,y=index%col;              //这边注意是要对col进行取模，而不是对row取模
                for(int i=0;i<4;i++){
                    next_row=x+next_step[i][0],next_col=y+next_step[i][1];
                    if(next_row>=0&&next_row<row&&next_col>=0&&next_col<col&&grid[next_row][next_col]==1){
                        grid[next_row][next_col]=2;
                        total--;
                        q.push(next_row*col+next_col);
                    }
                }
                q.pop();
                sz--;
            }
            cnt++;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<grid[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<total<<endl;


        if(total>0){
            return -1;
        }
        return cnt-1;
    }
};