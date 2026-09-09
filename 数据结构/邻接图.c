#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Edge {
	int to;
	int dis;
	int next;
}edge[1000];

int head[1000], num_edge = 0;

void add_edge(int from, int to, int dis) {
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	head[from] = num_edge;
}

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, d;
		scanf_s("%d %d %d", &u, &v, &d);
		add_edge(u, v, d);
	}
	for (int i = head[1]; i != 0; i = edge[i].next) {
		;
	}
	return 0;
}