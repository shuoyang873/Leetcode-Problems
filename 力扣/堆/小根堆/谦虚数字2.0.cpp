/*
谦虚数字
描述

给定一个包含 K 个不同质数的集合 S = {p₁, p₂, ..., pₖ}。

如果一个数的质因子全部属于集合 S，那么我们就称这个数为谦虚数字。

例如，p₁、p₁p₂、p₁p₁、p₁p₂p₃...这些数字都是谦虚数字。

现在给定整数 K 和集合 S，请你求出从小到大第 N 个谦虚数字是多少。

注意，我们规定 1 不是谦虚数字。


输入

第一行包含两个整数 K 和 N。

第二行包含 K 个质数。


输出

输出一个整数，表示第 N 大的谦虚数字。

数据范围

1 ≤ K ≤ 100，

1 ≤ N ≤ 10⁵

数据保证，答案在 int 范围内。


输入样例 1 

4 19
2 3 5 7
输出样例 1

27
来源


*/


#include<iostream>
#include<algorithm>
#include<vector>
//这边采用多指针的方式来解决，每个质数都对应一个指针，这个指针指向的是该质数所要相乘的谦虚数（因为谦虚数是通过质数与质数，质数与谦虚数相乘得到的）
using namespace std;
int main() {
	int n, k;
	cin >> k >> n;
	vector<long long>prime(k);
	vector<int>p(k,0);          //每个质数的指针都先初始化为0
	vector<long long>h(100005);
	h[0] = 1;                   //让谦虚数数组的第一个元素为1，作为乘法的单元，但是不计入谦虚数中，类似于一个哨兵一样
	for (int i = 0; i < k; i++) {
		cin >> prime[i];
	}
	for (int i = 1; i <= n; i++) {
		long long min_val = 2e18;       //计算每个位置的谦虚数，要找到当前最小
		for (int j = 0; j < k; j++) {
			long long cur = (long long)h[p[j]] * prime[j];    //这个是计算当前质数和该质数指向的谦虚数的乘积
			min_val = cur < min_val ? cur : min_val;          //取较小值进行更新
		}
		//因为这个质数数组里面的数据是从小到大进行排列，所以每次进行计算的时候，都是往大的方向走
		h[i] = min_val;
		for (int j = 0; j < k; j++) {
			if ((long long)h[p[j]] * prime[j] == min_val) {
				p[j]++;          //防止重复，如果当前质数和他指针指向的谦虚数的乘积跟我们刚刚得到的
			}
		}
	}
	cout << h[n] << endl;      //输出第n个元素就是我们所要找的谦虚数
	return 0;
}