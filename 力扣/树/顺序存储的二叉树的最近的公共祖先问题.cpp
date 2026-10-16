/*
3.2 顺序存储的二叉树的最近的公共祖先问题
分数 30
作者 DS课程组
单位 浙江大学
设顺序存储的二叉树中有编号为 i 和 j 的两个结点，请设计算法求出它们最近的公共祖先结点的编号和值。

输入格式:
第 1 行给出正整数 n（≤1000），即顺序存储的最大容量；第 2 行给出 n 个非负整数，其间以空格分隔。其中 0 代表二叉树中的空结点（如果第 1 个结点为 0，则代表一棵空树）；第 3 行给出一对结点编号 i 和 j。

题目保证输入正确对应一棵二叉树，且 1≤i,j≤n。

输出格式:
如果 i 或 j 对应的是空结点，则输出 ERROR: T[x] is NULL，其中 x 是 i 或 j 中先发现错误的那个编号；否则在一行中输出编号为 i 和 j 的两个结点最近的公共祖先结点的编号和值，其间以 1 个空格分隔。

输入样例1：
15
4 3 5 1 10 0 7 0 2 0 9 0 0 6 8
11 4
输出样例1：
2 3
输入样例2：
15
4 3 5 1 0 0 7 0 2 0 9 0 0 6 8
12 8
输出样例2：
ERROR: T[12] is NULL
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//这道题不适合用建树的方式，我尝试了建树的方式，感觉很麻烦，这道题直接使用当前结点i，左子节点2*i，右子节点2*i+1的关系来解题
int main() {
	int n;
	cin >> n;
	vector<int>node(n + 1, 0);
    //寻找公共父节点的思路是先记录下来其中一个结点的所有父节点（包括他本身），然后让另一个结点开始查找自己的父节点，看有没有和另一个结点的父节点对应
	vector<int>parent;
	for (int i = 1; i <= n; i++) {
		cin >> node[i];
	}
	int i, j;
	cin >> i >> j;
	
	if (node[1] == 0 || node[i] == 0) {
		cout << "ERROR: T[" << i << "] is NULL" << endl;
		return 0;
	}
	if (node[j] == 0) {
		cout << "ERROR: T[" << j << "] is NULL" << endl;
		return 0;
	}

	while (i > 0) {
		parent.push_back(i);    //这边存储的是其中一个节点的父节点的下标，而不是父节点的值
		i /= 2;      //因为当前的结点也要存，所以i/=2要放在后面
	}
	while (j > 0) {
		for (int pos = 0; pos < parent.size(); pos++) {
			if (j == parent[pos]) {
				cout << j << ' ' << node[j]<<endl;
				return 0;
			}
		}
		j /= 2;
	}
	return 0;
}