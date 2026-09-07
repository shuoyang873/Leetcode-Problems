/*
2、递归倒置字符数组
描述
完成一个递归程序，倒置字符数组。并打印实现过程
递归逻辑为：
当字符长度小于等于1时，直接返回不输出。
否则，调换首尾两个字符，再递归倒置字符数组的剩下部分。
输入
字符数组长度及该数组，空格隔开
输出
在求解过程中，打印字符数组的变化情况。
最后空一行，在程序结尾处打印倒置后该数组的各个元素。
输入样例 1 
5 abcde
输出样例 1
ebcda
edcba

edcba
输入样例 2 
1 a
输出样例 2

a
*/


#include<iostream>
#include<string>
using namespace std;
int n;
string s;
void reverse_string(int l, int r) {
	if (l >= r) {
		return;
	}
	else {
		swap(s[l++], s[r--]);
		for (int i = 0; i < n; i++) {
			cout << s[i];
		}
		cout << endl;
		reverse_string(l, r);
	}
}


int main() {
	cin >> n;
	cin >> s;
	reverse_string(0, n - 1);
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	return 0;
}