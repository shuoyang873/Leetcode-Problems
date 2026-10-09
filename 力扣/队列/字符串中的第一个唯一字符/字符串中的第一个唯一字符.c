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

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int firstUniqChar(char* s) {
    int ch[26]={0};               //这边提交的话，数组不可以开在全局里面，不然会出错，很奇怪
    //或者可以使用memset函数:memset(ch,0,sizeof(ch));
    //注意，memset函数是在string.h的头文件里面
    for(int i=0;i<strlen(s);i++){       //这边有一个注意点，就是计算char*s的长度，使用的是strlen，而计算int这类数组的长度，使用的是sizeof这个函数，两个使用的函数是不一样的
        ch[s[i]-'a']++;
    }
    int pos=-1;
    for(int i=0;i<strlen(s);i++){
        if(ch[s[i]-'a']==1){
            pos=i;
            break;
        }
    }
    return pos;
}