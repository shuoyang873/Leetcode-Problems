/*
1.3 两个有序链表序列的交集
分数 40
作者 DS课程组
单位 浙江大学
已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。

输入格式:
输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。数字用空格间隔。

输出格式:
在一行中输出两个输入序列的交集序列，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

输入样例:
1 2 5 -1
2 4 5 8 10 -1
输出样例:
2 5
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


int main() {
	unordered_map<int, int>mp1, mp2;
	int v;
	cin >> v;
	while (v != -1) {
		mp1[v]++;
		cin >> v;
	}
	cin >> v;
	while (v != -1) {
		mp2[v]++;
		cin >> v;
	}
	vector<int>ans;
	bool has_output = false;
	for (auto it : mp1) {
		if (mp2.count(it.first)) {
			has_output = true;
			int min_n = min(it.second, mp2[it.first]);
			for (int j = 0; j < min_n; j++) {
				ans.push_back(it.first);
			}
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) {
		printf("NULL\n");
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1) {
			cout << ' ';
		}
	}
	cout << endl;
	return 0;
}