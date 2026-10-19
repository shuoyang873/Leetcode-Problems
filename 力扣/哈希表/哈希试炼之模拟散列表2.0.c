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

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define N 100010          //这个设定的是操作的数量
#define H 300070          //这个设定的是哈希表的大小，哈希表的大小一般是操作数的3倍大小
#define NULL_VALUE 0x3f3f3f3f      //因为题目中说数据的大小会达到10的8次方，所以这边设定的NULL_VALUE达到10的9次方，不在输入范围内，所以可以用来表示空
int h[H];

//find函数负责找到当前的数据所应该在的位置，不负责插入和查询
int find(int x) {
	int k = (x % H + H) % H;                  //这个是哈希表下标的计算公式，要记住
	while (h[k] != NULL_VALUE && h[k] != x) {
		k++;                                      //这个循环的目的是防止覆盖，因为不同的数据可能通过公式得到的下标是同一个，所以要进行循环来找到可以使用的地方
		if (k == H) {           //如果当前的位置已经超出了哈希表的大小，那么就要从头开始找
			k = 0;
		}
	}
	return k;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < H; i++) {
		h[i] = NULL_VALUE;
	}
	for (int i = 0; i < n; i++) {
		char c;
		int x;
		getchar();              //这边记得要用getchar来吸收前面的换行符
		scanf("%c %d", &c, &x);
		int k = find(x);
		if (c == 'I') {
			h[k] = x;           //如果是插入，直接赋值
		}
		else if (c == 'Q') {
			if (h[k] == x) {           //如果是询问，如果当前的位置和x的值相同，那么说应已经存在，那么就要输出yes
				printf("Yes\n");
			}
			else {
				printf("No\n");         //反之，输出no
			}
		}
	}
	return 0;
}