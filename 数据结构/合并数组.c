#include<stdio.h>         //时间复杂度是O(n),空间复杂度是O(n),如果是在原来的数组上进行操作，那么空间复杂度是O(1)
#include<stdlib.h>
#include<math.h>

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	int num1[100] = { 0 }, num2[100] = { 0 }, ans[202] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num1[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &num2[i]);
	}
	int pos1 = 0, pos2 = 0, pos = 0;
	while (pos1 < n && pos2 < m) {
		if (num1[pos1] < num2[pos2]) {
			ans[pos++] = num1[pos1++];
		}
		else {
			ans[pos++] = num2[pos2++];
		}
	}
	while (pos1 < n) {
		ans[pos++] = num1[pos1++];
	}
	while (pos2 < m) {
		ans[pos++] = num2[pos2++];
	}

	for (int i = 0; i < n + m; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}