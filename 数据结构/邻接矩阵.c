#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_SIZE 100
int matrix[MAX_SIZE][MAX_SIZE];

int main() {
	memset(matrix, 0, sizeof(matrix));          //这边采用memset进行初始化，将所有的值都初始化为0
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, w;
		scanf_s("%d %d %d", &x, &y, &w);
		matrix[x][y] = w;                     //目前的代码是无向图，表示从x到y的路径长度是w，同时从y到x的路径长度也是w
		matrix[y][x] = w;                     //如果是有向图，那么应该不写这句代码
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}