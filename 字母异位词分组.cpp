/*
49. 字母异位词分组
已解答
中等
相关标签
premium lock icon
相关企业
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

解释：

在 strs 中没有字符串可以通过重新排列来形成 "bat"。
字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
示例 2:

输入: strs = [""]

输出: [[""]]

示例 3:

输入: strs = ["a"]

输出: [["a"]]

 

提示：

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>kind;          //这边采用哈希表，前面是对应的已排好顺序的字符串，后面是与他一样拥有相同字母的字符串
        for(const auto&s:strs){
            string tmp=s;         //需要有一个临时的字符串，把他进行排序
            sort(tmp.begin(),tmp.end());
            kind[tmp].push_back(s);        //如果字母相同，那么就放入对应的哈希表里面，如果没有对应的字符串，那么哈希表也会自动创建一个新的空间
        }
        vector<vector<string>>ans;
        for(const auto&c:kind){
            ans.push_back(c.second);        //注意这里是c.second,后面没有(),不然会出错
        }
        return ans;
    }
};