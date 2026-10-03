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
    int firstUniqChar(string s) {      //我的这个解法采用队列和哈希表
    //这边为什么会想到用队列：因为队列有先进先出的特性，可以用他来找第一个和符合条件的元素，而这道题是要找第一个唯一的字符，所以可以考虑使用队列
        int n=s.size();
        queue<int>q;                   //这边采用队列，用来记录字符的下标，而不是记录字符
        unordered_map<char,int>mp;     //这边这个哈希表是用来存储每个字符对应的出现的数量
        for(int i=0;i<n;i++){
            q.push(i);                  //先将当前的字符的下标入队
            mp[s[i]]++;                 //将当前字符的数量+1
            while(!q.empty()&&mp[s[q.front()]]>1){           //接着来判断队列是否为空，如果为空，那么无法弹出，如果非空，且当前下标为front的字符的数量不为1，说明不符合条件，那么将其弹出，并循环这个过程直到第一个字符的数量==1
                q.pop();
            }
        }
        return q.empty()?-1:q.front();           //最终按照题目要求返回答案
    }
};