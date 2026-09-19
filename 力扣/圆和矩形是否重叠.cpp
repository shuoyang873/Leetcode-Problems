/*

代码
测试用例
测试用例
测试结果
1401. 圆和矩形是否有重叠
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你一个以 (radius, xCenter, yCenter) 表示的圆和一个与坐标轴平行的矩形 (x1, y1, x2, y2) ，其中 (x1, y1) 是矩形左下角的坐标，而 (x2, y2) 是右上角的坐标。

如果圆和矩形有重叠的部分，请你返回 true ，否则返回 false 。

换句话说，请你检测是否 存在 点 (xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。

 

示例 1 ：


输入：radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
输出：true
解释：圆和矩形存在公共点 (1,0) 。
示例 2 ：

输入：radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
输出：false
示例 3 ：


输入：radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
输出：true
 
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dis=0;                //这边采用计算圆心到最近的边的距离的方法
        //如果圆心在矩形外部，计算圆心到矩形左侧和矩形右侧的距离的最小值
        if(xCenter<x1||xCenter>x2){
            dis+=min(pow(xCenter-x1,2),pow(xCenter-x2,2));
        }
        //如果圆心在矩形外部，计算圆心到矩形上边界和下边界的距离的最小值
        if(yCenter<y1||yCenter>y2){
            dis+=min(pow(yCenter-y1,2),pow(yCenter-y2,2));
        }
        //最后距离边的最小距离之和就是圆心到这个矩形的最近的点的距离的平方
        return dis<=radius*radius;       //最后根据r和距离的比较判断圆是否和矩形相交
    }
};