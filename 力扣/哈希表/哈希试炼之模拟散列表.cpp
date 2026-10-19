/*
哈希试炼之模拟散列表
描述

维护一个集合，支持如下几种操作：

“I x”，插入一个数 x；

“Q x”，询问数 x 是否在集合中出现过；

现在要进行 N 次操作，对于每个询问操作输出对应的结果。

数据范围：

1≤N≤10^5

−10^9≤x≤10^9


输入

第一行包含整数 N，表示操作数量。

接下来 N 行，每行包含一个操作指令，操作指令为“I x”，“Q x”中的一种。


输出

对于每个询问指令“Q x”，输出一个询问结果，如果 x 在集合中出现过，则输出“Yes”，否则输出“No”。

每个结果占一行。


输入样例 1 

5
I 1
I 2
I 3
Q 2
Q 5
输出样例 1

Yes
No
来源

xmu


*/

#include<iostream>
#include<unordered_set>      //这边用了我一个之前不知道的头文件，就是unordered_set头文件，我之前只知道unordered_map这个头文件，然后每次想到里面必须存键值对，所以就没有使用，这个的话可以只存一个数据，同时防止重复
using namespace std;
int main() {
	int n;
	cin >> n;
	unordered_set<int>s;
	for (int i = 0; i < n; i++) {
		char c;
		int a;
		cin >> c >> a;
		if (c == 'I') {
			s.insert(a);             //这边的操作和set一样，是通过insert来进行数据的插入存储，如果是unordered_map，是通过给键赋值
		}
		else {
			if (s.count(a)) {          //这边的操作和unordered_map一样，就是用count来判断是否已经存在
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}