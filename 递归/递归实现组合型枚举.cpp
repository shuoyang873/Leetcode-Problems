/*
递归实现组合型枚举
描述
从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。
输入
两个整数 n,m ,在同一行用空格隔开。
数据范围
n>0 ,
0≤m≤n ,
n+(n−m)≤25
输出
按照从小到大的顺序输出所有方案，每行 1 个。
首先，同一行内的数升序排列，相邻两个数用一个空格隔开。
其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。
输入样例 1 
5 3
输出样例 1
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
*/


#include<iostream>
using namespace std;

int path[30], use[30];
int n, m;
void dfs(int cnt, int cur) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i];
			if (i < m - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
	for (int i = cur; i <= n; i++) {
		if (use[i] == 0) {
			path[cnt] = i;
			use[i] = 1;
			dfs(cnt + 1, i + 1);
			use[i] = 0;
		}
	}
}


int main() {
	cin >> n >> m;
	dfs(0, 1);
	return 0;
}