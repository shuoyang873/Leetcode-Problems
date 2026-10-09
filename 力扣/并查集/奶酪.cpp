/*
奶酪
描述

现有一块大奶酪，它的高度为 h，它的长度和宽度我们可以认为是无限大的，奶酪中间有许多半径相同的球形空洞。

我们可以在这块奶酪中建立空间坐标系，在坐标系中，奶酪的下表面为 z=0，奶酪的上表面为 z=h。

现在，奶酪的下表面有一只小老鼠 Jerry，它知道奶酪中所有空洞的球心所在的坐标。

如果两个空洞相切或是相交，则 Jerry 可以从其中一个空洞跑到另一个空洞，特别地，如果一个空洞与下表面相切或是相交，Jerry 则可以从奶酪下表面跑进空洞；如果一个空洞与上表面相切或是相交，Jerry 则可以从空洞跑到奶酪上表面。

位于奶酪下表面的 Jerry 想知道，在不破坏奶酪的情况下，能否利用已有的空洞跑到奶酪的上表面去？


输入

每个输入文件包含多组数据。

输入文件的第一行，包含一个正整数 T，代表该输入文件中所含的数据组数。

接下来是 T 组数据，每组数据的格式如下：

第一行包含三个正整数 n，h 和 r，两个数之间以一个空格分开，分别代表奶酪中空洞的数量，奶酪的高度和空洞的半径。

接下来的 n 行，每行包含三个整数 x、y、z，两个数之间以一个空格分开，表示空洞球心坐标为 (x,y,z)。

注意：
空间内两点 P1(x1,y1,z1)、P2(x2,y2,z2) 的距离公式如下：

dist(P1,P2)=√[(x1−x2)²+(y1−y2)²+(z1−z2)²]

数据范围

1≤n≤1000, 1≤h,r≤10⁹, T≤20, 坐标的绝对值不超过10⁹


输出

输出文件包含 T 行，分别对应 T 组数据的答案，如果在第 i 组数据中，Jerry 能从下表面跑到上表面，则输出 Yes，如果不能，则输出 No。


输入样例 1 

3
2 4 1
0 0 1
0 0 3
2 5 1
0 0 1
0 0 4
2 5 2
0 0 2
2 0 4
输出样例 1

Yes
No
Yes
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct hole {
	long long x, y, z;
};

struct DSU {
	vector<int>parent;
	DSU(int n) {
		parent = vector<int>(n + 1);
		for (int i = 0; i < n + 1; i++) {
			parent[i] = i;
		}
	}

	int find(int index) {
		if (parent[index] == index) {
			return index;
		}
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

int calculate_distance(hole& h1, hole& h2) {
	long long dis_x = h1.x - h2.x;
	long long dis_y = h1.y - h2.y;
	long long dis_z = h1.z - h2.z;
	return dis_x * dis_x + dis_y * dis_y + dis_z * dis_z;
}

void solve() {
	int n, h, r;
	if (!(cin >> n >> h >> r))return;
	vector<hole>holes(n);
	DSU dsu(n + 1);
	int S = 0, E = n + 1;
	for (int i = 0; i < n; i++) {
		cin >> holes[i].x >> holes[i].y >> holes[i].z;
		if (holes[i].z <= r) {
			dsu.unite(S, i + 1);
		}
		if (holes[i].z + r >= h) {
			dsu.unite(i + 1, E);
		}
		for (int j = 0; j < i; j++) {
			if (calculate_distance(holes[i], holes[j])<=4*r*r) {
				dsu.unite(i + 1, j + 1);
			}
		}
	}
	if (dsu.find(S) == dsu.find(E)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t) {
		solve();
		t--;
	}
	return 0;
}