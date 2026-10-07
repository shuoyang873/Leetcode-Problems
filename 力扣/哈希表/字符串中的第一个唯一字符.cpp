/*
387. 字符串中的第一个唯一字符
已解答
简单
相关标签
premium lock icon
相关企业
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

 

示例 1：

输入: s = "leetcode"
输出: 0
示例 2:

输入: s = "loveleetcode"
输出: 2
示例 3:

输入: s = "aabb"
输出: -1
 

提示:

1 <= s.length <= 105
s 只包含小写字母
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {         //这个是我第一次的解法，直接采用哈希表来计数
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;              //对每个字符的数量进行计数
        }
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1){      //从头开始遍历字符串，如果遍历到的字符串的数量是1，那么说明找到答案，直接返回下标
                return i;
            }
        }
        return -1;
    }
};