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

#include<stdio.h>
#include<stdlib.h>
#include<math.h>              //第一次是因为数组开的太小，然后改成static之后因为数据量过大，导致运行超时，这道题用c语言的解法是自己手搓哈希表

int main() {
    //这边学到的一个点就是如果数组开的太小，会导致栈溢出，但是可以通过使用static来解决
	int* nums1 = (int*)malloc(1000001 * sizeof(int)), * nums2 = (int*)malloc(1000001 * sizeof(int)), (*sort1)[2] = (int(*)[2])malloc(1000001 * sizeof(int[2])), (*sort2)[2] = (int(*)[2])malloc(1000001 * sizeof(int[2]));
	int cnt1 = 0, cnt2 = 0;
	int v;
	scanf_s("%d", &v);
	while (v != -1) {
		nums1[++cnt1] = v;
		scanf_s("%d", &v);              //还有要注意的点就是输入的数据可能为空，所以要提前判断，否则可能会访问到无效数据，导致错误
	}
	scanf_s("%d", &v);
	while (v != -1) {
		nums2[++cnt2] = v;
		scanf_s("%d", &v);
	}
	int sort1[100][2] = { 0 }, sort2[100][2] = { 0 };
	int pos1 = 0, pos2 = 0;
	for (int i = 1; i <= cnt1; i++) {
		if (nums1[i] != nums1[i - 1]) {
			pos1++;
			sort1[pos1][0] = nums1[i];
			sort1[pos1][1]++;
		}
		else {
			sort1[pos1][1]++;
		}
	}
	for (int i = 1; i <= cnt2; i++) {
		if (nums2[i] != nums2[i - 1]) {
			pos2++;
			sort2[pos2][0] = nums2[i];
			sort2[pos2][1]++;
		}
		else {
			sort2[pos2][1]++;
		}
	}
	int ans[205] = { 0 }, pos = 0;
	for (int i = 1; i <= pos1; i++) {
		for (int j = 1; j <= pos2; j++) {
			if (sort1[i][0] == sort2[j][0]) {
				int min_n = min(sort1[i][1], sort2[j][1]);
				for (int k = 0; k < min_n; k++) {
					ans[pos++] = sort1[i][0];
				}
			}
		}
	}
	for (int i = 0; i < pos; i++) {
		printf("%d", ans[i]);
		if (i < pos - 1) {
			printf(" ");
		}
	}
	return 0;
}