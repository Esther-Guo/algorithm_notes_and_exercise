// http://codeup.cn/problem.php?cid=100000575&pid=4

/*
注意交换起点终点位置，以保证起点始终小于终点
注意初始化语句的位置
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int n, m;
	int dist[100000] = { 0 };
	int start, end;
	int temp;
	int pos = 0, neg = 0; //正向距离，反向距离
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &dist[i]);
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d", &start, &end);
			// swap start and end
			if (start > end) {
				temp = start;
				start = end;
				end = temp;
			}
			// positive distance
			for (int i = start; i < end; i++) {
				pos += dist[i - 1];
			}
			// negative distance
			for (int j = 1; j < start; j++) {
				neg += dist[j - 1];
			}
			for (int j = end; j <= n; j++) {
				neg += dist[j - 1];
			}
			printf("%d\n", pos > neg ? neg : pos);
			pos = neg = 0;
		}
		memset(dist, 0, sizeof(dist));
		pos = neg = 0;
	}
	return 0;
}