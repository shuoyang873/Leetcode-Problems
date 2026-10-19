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
#include<queue>
#include<set>              //这题采用小根堆的思路，因为当前的第n个最小的谦虚数不确定，所以只能边算边计数，然后小根堆的话，每次都是将最小的数放到最前面，所以pop到第n次的时候，这个数字就是我们要找的第n个谦虚数了
//这边因为会出现重复的情况，所以我们采用set来去除重复元素
using namespace std;
int main() {
	int k, n;
	cin >> k >> n;
	vector<int>prime(k);
	priority_queue<long long, vector<long long>, greater<long long>>q;     //小根堆写法
	set<long long>vis;       //记录是否重复出现
	for (int i = 0; i < k; i++) {
		cin >> prime[i];
		q.push(prime[i]);
		vis.insert(prime[i]);
	}
	long long cur = 0;        //这边cur需要放在外面，因为第n次弹出的数据就是我们要找的答案，如果放在里面，外面输出的时候访问不到，只能访问到第n+1个元素，因为第n个元素已经被弹出了
	for (int i = 0; i < n; i++) {    //重复n次，每次把小根堆的堆顶的元素取出，然后分别跟质数数组里面的元素相乘，如果没有重复出现，那么就把他放进小根堆里面
		cur = q.top();
		q.pop();
		for (int j = 0; j < k; j++) {
			long long res = cur * prime[j];
			if (vis.insert(res).second) {      //注意这里set的用法，这边的insert后面的是()，而不是[]，这点要注意区分
				q.push(res);
			}
		}
	}
	cout << cur << endl;
	return 0;
}