// http://codeup.cn/problem.php?cid=100000576&pid=3

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int n, m;
	int an[100] = { 0 };
	int num;
	int j;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &an[i]);
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &num);
			for (j = 0; j < n; j++) {
				if (num == an[j]) {
					printf("YES\n");
					break; // 及时终止循环
				}
			}
			if (j == n) printf("NO\n");
		}
		memset(an, 0, sizeof(an));
	}
	return 0;
}