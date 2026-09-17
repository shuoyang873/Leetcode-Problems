/*
1.1 约瑟夫环
分数 20
作者 李廷元
单位 中国民用航空飞行学院
N个人围成一圈顺序编号，从1号开始按1、2、3......顺序报数，报p者退出圈外，其余的人再从1、2、3开始报数，报p的人再退出圈外，以此类推。
请按退出顺序输出每个退出人的原序号。

输入格式:
输入只有一行，包括一个整数N(1<=N<=3000)及一个整数p(1<=p<=5000)。

输出格式:
按退出顺序输出每个退出人的原序号，数据间以一个空格分隔，但行尾无空格。

输入样例:
在这里给出一组输入。例如：

7 3
输出样例:
3 6 2 7 5 1 4

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, p;
	cin >> n >> p;
	vector<bool>visited(n + 1);
	vector<int>ans(n);
	int cur = 1;
	int tot_cnt = 0, cnt = 0;
	while (tot_cnt < n) {
		if (!visited[cur]) {
			cnt++;
			if (cnt == p) {
				ans[tot_cnt++] = cur;
				visited[cur] = true;
				cnt = 0;
			}
		}
		cur = cur + 1;
		if (cur > n)cur = cur % n;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
        if(i<n-1){
            cout<<' ';
        }
	}
    cout<<endl;
	return 0;
}