/*
739. 每日温度
已解答
中等
相关标签
premium lock icon
相关企业
提示
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]
 

提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/


#include<bits/stdc++.h>.h>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {      //这边采用单调栈的方式
        //使用单调栈的原因：找到下一个最小/最大的数，属于当前未知答案，需要存储前面的数据
        //像这种找到下一个符合条件的元素的题目，可以考虑使用单调栈
        //如果要找下一个更大的数，那么使用递减单调栈，如果要找下一个更小的数，那么使用递增单调栈
        int n=temperatures.size();
        stack<int>stk;
        vector<int>vc(n,0);            //用来记录每个位置的答案
        for(int i=0;i<n;i++){
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){     //如果当前位置的温度大于栈里面存储的温度，那么说明找到了第一个更大的温度
                int preindex=stk.top();
                stk.pop();
                int cnt=i-preindex;    //计算距离差值
                vc[preindex]=cnt;      //记录答案
                //注意：！！！！！！这边这个是记录的preindex的答案，而不是i的答案，因为这个是记录的是第一个更大值和该值之间的下标距离
            }
            stk.push(i);         //将比当前值小的温度都比较完，记录好数据之后，那么当前的温度就应该入栈
        }
        return vc;
    }
};