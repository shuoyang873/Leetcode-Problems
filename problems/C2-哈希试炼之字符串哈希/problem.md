# C2 哈希试炼之字符串哈希

- 比赛：2026年蓝桥杯集训队之高级数据结构
- 题型：OI
- 难度：Mid
- 语言：C, C++, Java, Python3

## 题目描述

<p>给定一个长度为<code>n</code>的字符串，再给定<code>m</code>个询问，每个询问包含四个整数<code>l1</code>,<code>r1</code>,<code>l2</code>,<code>r2</code>。</p><p>请你判断<code>[l1, r1]</code>和<code>[l2, r2]</code>这两个区间所包含的字符串子串是否完全相同。</p><p>字符串中只包含大小写英文字母和数字。</p>

## 输入描述

<p>第一行包含整数<code>n</code>和<code>m</code>，表示字符串长度和询问次数。</p><p>第二行包含一个长度为<code>n</code>的字符串，字符串中只包含大小写英文字母和数字。</p><p>接下来<code>m</code>行，每行包含四个整数<code>l1</code>,<code>r1</code>,<code>l2</code>,<code>r2</code>，表示一次询问所涉及的两个区间。</p><p>注意，字符串的位置从 1 开始编号。</p>

## 输出描述

<p>对于每个询问输出一个结果，如果两个字符串子串完全相同则输出<code>Yes</code>，否则输出<code>No</code>。</p><p>每个结果占一行。</p><p><strong>数据范围</strong>1≤<code>n</code>,<code>m</code>≤10^5</p>

## 样例

### 样例 1

#### 输入

```text
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
```

#### 输出

```text
Yes
No
Yes
```
