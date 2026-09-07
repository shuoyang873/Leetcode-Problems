/*
3、递归实现排列型枚举
描述
把 1∼n 这 n 个整数排成一行后随机打乱顺序，输出所有可能的次序。
输入
一个整数 n。
数据范围
1≤n≤9
输出
按照从小到大的顺序输出所有方案，每行 1 个。
首先，同一行相邻两个数用一个空格隔开。
其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。
输入样例 1 
3
输出样例 1
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/


#include<iostream>
using namespace std;

int n, num[10], path[10];
void permutation(int cnt) {
	if (cnt == n) {                 //这边的cnt就相当于是计数当前填了多少个数字，所以当cnt==n的时候，说明已经填了n个数字，所以已经填满了，可以进行输出，所以以n为递归出口
		for (int i = 0; i < n; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (num[i] == 0) {
			path[cnt] = i;
			num[i] = 1;
			permutation(cnt+1);     //这边有一个注意点，就是cnt不要在前面的递归中进行自增，不然递归回来，cnt已经不是原本的值，会导致错乱，正确的应该是cnt不变，然后在递归函数里面进行+1！！！！！！！！这很重要，之前没有碰到过这种问题
			num[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	permutation(0);
	return 0;
}