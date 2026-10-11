/*
并查集试炼之合并集合
描述

一共有n个数，编号是1~n，最开始每个数各自在一个集合中。

现在要进行m个操作，操作共有两种：

“M a b”，将编号为a和b的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
“Q a b”，询问编号为a和b的两个数是否在同一个集合中；
数据范围：1≤n,m≤10^5


输入

第一行输入整数n和m。

接下来m行，每行包含一个操作指令，指令为“M a b”或“Q a b”中的一种。


输出

对于每个询问指令”Q a b”，都要输出一个结果，如果a和b在同一集合内，则输出“Yes”，否则输出“No”。

每个结果占一行。


输入样例 1 

4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例 1

Yes
No
Yes
*/


//这道题第一次写的时候基本没有问题，但是有两个很致命的bug
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;

struct DSU {
	vector<int>parent;
	DSU(int n) {
		parent = vector<int>(n+1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	
	int find(int index) {
		if (parent[index] == index)return index;          //这边我第一次写的时候写成了赋值语句，只有一个=，这边判断是否相等的话要用==，这个是个小细节，但是很容易犯错！！！！要重点注意，之前也有犯过几次一样的错误
		return parent[index] = find(parent[index]);
	}

	void unite(int i, int j) {
		int root_i = find(i);
		int root_j = find(j);
		if (root_i != root_j) {
			parent[root_i] = parent[root_j];
		}
	}
};



void solve() {
	DSU dsu(n);
	for (int i = 0; i < m; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == 'M') {
			if (dsu.find(a)==dsu.find(b)) {      //还有第二个bug就是判断两个是否在相同的集合的时候，是用的find的函数，而不是直接判断他们的parent是否相等！！！！
				continue;
			}
			else {
				dsu.unite(a, b);
			}
		}
		else if (c == 'Q') {
			if (dsu.find(a) == dsu.find(b)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return;
	
}

int main() {
	cin >> n >> m;
	solve();
	return 0;
}