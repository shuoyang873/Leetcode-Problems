/*
402. 移掉 K 位数字
已解答
中等
相关标签
premium lock icon
相关企业
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

 
示例 1 ：

输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
示例 2 ：

输入：num = "10200", k = 1
输出："200"
解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 ：

输入：num = "10", k = 2
输出："0"
解释：从原数字移除所有的数字，剩余为空就是 0 。
 

提示：

1 <= k <= num.length <= 105
num 仅由若干位数字（0 - 9）组成
除了 0 本身之外，num 不含任何前导零
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>stk;
        for(auto&c:num){
            while(stk.size()>0&&c<stk.back()&&k>0){
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
        
        while(k>0){
            stk.pop_back();
            k--;
        }
        string ans;
        bool is_lead_zero=true;
        for(auto&c:stk){
            if(is_lead_zero&&c=='0'){
                continue;
            }
            is_lead_zero=false;
            ans+=c;
        }
        return ans.size()==0?"0":ans;
    }
};