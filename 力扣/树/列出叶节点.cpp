/*
3.1 列出叶结点
分数 30
作者 陈越
单位 浙江大学
对于给定的二叉树，本题要求你按从上到下、从左到右的顺序输出其所有叶结点。

输入格式：
首先第一行给出一个正整数 n（≤10），为树中结点总数。树中的结点从 0 到 n−1 编号。随后 n 行，每行给出一个对应结点左右孩子的编号。如果某个孩子不存在，则在对应位置给出 "-"。编号间以 1 个空格分隔。

输出格式：
在一行中按规定顺序输出叶结点的编号。编号间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
输出样例：
4 1 5
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>node(n, { -1,-1 });
	vector<int>parent(n, -1);
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;
		if (isdigit(a)) {
			node[i].first = a - '0';      //注意，这边要减去的字符是‘0’，而不是‘a'，因为这边的这些如果是数字，那么需要正确记录他们的数值，所以要-’0‘！！！！
			parent[a - '0'] = i;
		}
		/*else {
			node[i].first = -1;
		}*/
		if (isdigit(b)) {
			node[i].second = b - '0';
			parent[b - '0'] = i;
		}
		/*else {
			node[i].second = -1;
		}*/
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (parent[i] == -1) {
			root = i;
			break;
		}
	}
	queue<int>q;
	vector<int>ans;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		while (sz) {
			int cur = q.front();
			if (node[cur].first != -1)q.push(node[cur].first);
			if (node[cur].second != -1)q.push(node[cur].second);
			if (node[cur].first == -1 && node[cur].second == -1)ans.push_back(cur);
			sz--;
			q.pop();
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1)cout << ' ';
	}
	cout << endl;
	return 0;
}