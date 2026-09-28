/*
316. 去除重复字母
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
 

注意：该题与 1081 https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters 相同
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>vis(26,0);
        vector<int>cnt(26,0);
        for(char c:s){
            cnt[c-'a']++;
        }
        stack<char>stk;
        for(char c:s){
            if(!vis[c-'a']){
                while(!stk.empty()&&stk.top()>c&&cnt[stk.top()-'a']>0){
                    vis[stk.top()-'a']=0;
                    stk.pop();
                }
                stk.push(c);
                vis[c-'a']=1;
            }
            cnt[c-'a']--;
        }
        string ans;
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};