# 209. 长度最小的子数组

**难度：** 中等

## 题目描述

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

**示例 1：**
```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**示例 2：**
```
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3：**
```
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```

## 提示

- 1 <= target <= 109
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104

## 进阶

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

## 代码

详见 [main.cpp](main.cpp)。

### 正确代码

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        if(n==0)return n;
        int min_len=INT_MAX,sum=0;
        int pos1=0,pos2=0;
        while(pos2<n){
            sum+=nums[pos2];
            while(sum>=target){
                min_len=min(min_len,pos2-pos1+1);
                sum-=nums[pos1];
                pos1++;
            }
            pos2++;
        }
        if(min_len==INT_MAX)return 0;
        return min_len;
    }
};
```

---
*由 `leetcode_sync.py` 于 2026-08-24 20:31:09 自动生成*