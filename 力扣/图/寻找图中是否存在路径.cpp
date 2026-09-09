/*
1971. 寻找图中是否存在路径
已解答
简单
相关标签
premium lock icon
相关企业
有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。

请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。

给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。

 

示例 1：


输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
输出：true
解释：存在由顶点 0 到顶点 2 的路径:
- 0 → 1 → 2 
- 0 → 2
示例 2：


输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
输出：false
解释：不存在由顶点 0 到顶点 5 的路径.
 

提示：

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
不存在重复边
不存在指向顶点自身的边
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find_path(vector<vector<int>>&mat,vector<bool>&visited,int source,int destination){
        if(source==destination){
            return true;
        }
        visited[source]=true;              //将目前走过的结点标记为true
        for(auto&next:mat[source]){
            if(!visited[next]&&find_path(mat,visited,next,destination)){        //注意，此处可以不用恢复状态，与之前题目的区别：1、统计所有可能的路径，那么需要恢复状态；2、判断是否存在路径，可以不用恢复状态
            //这句的条件判断语句意思是，如果下一个结点没有被访问过，且通过下一个结点能够走到目的地，那么返回true
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {     //这边采用深度优先搜索的方式来寻找是否存在路径
        vector<vector<int>>mat(n);               //因为题目的输入无法快速得到当前结点的所有邻接点，所以重新使用一个数组，作为结点的邻接表
        for(auto&edge:edges){
            int x=edge[0],y=edge[1];
            //无向图
            mat[x].emplace_back(y);
            mat[y].emplace_back(x);
        }
        vector<bool>visited(n,false);        //这边的visited只需要一维的就可以，因为这个记录的是每个结点是否走过，不需要用二维的数组
        return find_path(mat,visited,source,destination);
    }
};