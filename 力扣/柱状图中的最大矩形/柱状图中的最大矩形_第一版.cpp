/*
84. 柱状图中最大的矩形
已解答
困难
相关标签
premium lock icon
相关企业
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4
 

提示：

1 <= heights.length <=105
0 <= heights[i] <= 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {          //这边采用单调栈的方法
        int n=heights.size();
        if(n==0)return 0;
        vector<int>left(n,0);             //这里的left数组和right数组用来记录按照每个位置的高度，向左和向右能够到达的最远的位置的下标
        vector<int>right(n,0);
        stack<int>stk;                   //声明一个栈，采用单调栈的方法
        for(int i=0;i<n;i++){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){           //这边的单调栈就是用来更新每个位置向左能够延申的最远的距离的下标
                stk.pop();              //如果当前栈里面存储的下标的高度大于等于位置i的高度，那么就要把当前位置的下标弹出，因为他不可能成为边界值
            }
            if(stk.empty()){
                left[i]=-1;              //判断当前栈里面是否还有值，如果没有值了，说明向左没有比当前值更小的值，所以可以设为虚拟哨兵节点-1
            }
            else{
                left[i]=stk.top();         //如果非空，那么说明找到了左边界的下标
            }
            stk.push(i);                 //这里栈的输入是push操作，没有像vector一样的push_back操作
        }
        stk=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){          //寻找右边界的下标也是同样的道理
                stk.pop();
            }
            if(stk.empty()){
                right[i]=n;
            }
            else{
                right[i]=stk.top();
            }
            stk.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);          //最后计算每个节点向左和向右延申的最大面积，注意，这里右边界下标减去左边界的下标之后要再减去1，是因为left数组记录的是该节点左侧第一个小于height[i]的下标，然后right数组记录的是该节点右侧第一个小于height[i]，所以要多减一个1
        }
        return ans;
    }
};