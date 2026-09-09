/*
997. 找到小镇的法官
已解答
简单
相关标签
premium lock icon
相关企业
小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。

如果小镇法官真的存在，那么：

小镇法官不会信任任何人。
每个人（除了小镇法官）都信任这位小镇法官。
只有一个人同时满足属性 1 和属性 2 。
给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。

如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。

 

示例 1：

输入：n = 2, trust = [[1,2]]
输出：2
示例 2：

输入：n = 3, trust = [[1,3],[2,3]]
输出：3
示例 3：

输入：n = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1
 
提示：

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
trust 中的所有trust[i] = [ai, bi] 互不相同
ai != bi
1 <= ai, bi <= n
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {             //我第一次写的代码，执行效率比较低
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));           //用邻接矩阵来记录每个人的信任情况
        int sz=trust.size();
        vector<bool>vc(n+1,false);                     //这个数组用来记录是否有信任其他人，方便后边筛选出没有信任任何人的人
        for(int i=0;i<sz;i++){
            int x=trust[i][0],y=trust[i][1];
            mat[x][y]=1;
            vc[x]=true;
        }
        vector<int>candidate;                    //记录没有信任其他人的人
        for(int i=1;i<=n;i++){
            if(!vc[i])candidate.push_back(i);
        }
        if(candidate.empty())return -1;            //如果都有信任的对象，那么返回-1

        for(int i=0;i<candidate.size();i++){       //处理没有信任对象的人
            int cnt=0;                    //计算信任他的人的个数
            for(int j=1;j<=n;j++){
                if(mat[j][candidate[i]]){           //如果有人信任他，那么邻接表里面的数值是1，cnt++
                    cnt++;
                }
            }
            if(cnt==n-1)return candidate[i];         //如果其他人都信任他，那么他就是法官，返回法官的下标
        }
        return -1;             //如果对于每个candidate里面的人，不是所有的人都信任他，那么说明没有法官
    }
};