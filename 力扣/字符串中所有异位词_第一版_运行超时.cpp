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
    vector<int> findAnagrams(string s, string p) {       //我第一次的思路是进行暴力枚举，从每个位置遍历过去，看排序后是否相同，但是对于后面大的数据，会导致超时
        int n=s.size(),len=p.size();
        sort(p.begin(),p.end());        //对p进行排序，确保是按照从小到大的顺序
        vector<int>ans;
        for(int ptr=0;ptr<=n-len;ptr++){
            string tmp=s.substr(ptr,len);          //用substr函数来截取字符串
            sort(tmp.begin(),tmp.end());           //排序比较是否相同
            if(tmp==p){
                ans.push_back(ptr);                //如果相同，记录下当前的下标
            }
        }
        return ans;
    }
};