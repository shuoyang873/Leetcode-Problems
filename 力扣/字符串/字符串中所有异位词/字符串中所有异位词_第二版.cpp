/*
438. 找到字符串中所有字母异位词
尝试过
中等
相关标签
premium lock icon
相关企业
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {          //这边采用滑动窗口
        int len_s=s.size(),len_p=p.size();           //先分别记录s和p的长度
        if(len_s<len_p)return {};               //处理特殊情况，如果len_s<len_p，那么说明肯定不会有异位词，直接返回空数组

        //重点，这边记录是否是异位词，直接转换为记录窗口内对应的字符的数量是否跟p相同，如果相同，那么肯定是字母异位词，反之，则不是
        vector<int>count_s(26);            //开大小26的数组，用来记录每个字母的数量
        vector<int>count_p(26);

        //先处理开头的字母
        for(int i=0;i<len_p;i++){
            count_p[p[i]-'a']++;       //这边采用-'a'的操作转换为数字，方便记录
            count_s[s[i]-'a']++;
        }
        vector<int>ans;
        if(count_p==count_s){
            ans.push_back(0);       //先判断开头的几个字母的数量，如果都相同，那么向ans数组中存入对应的开头标记0
        }


        //滑动数组的重点
        for(int i=0;i<len_s-len_p;i++){
            count_s[s[i]-'a']--;             //先把最前面的字母的数量-1，表示将最前面的字母推出窗口
            count_s[s[i+len_p]-'a']++;       //将后面的一个字母放入滑动窗口进行计数
            if(count_s==count_p){             //再次比较两个数组，如果相同，那么存入当前开头字母的下标，是i+1
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};