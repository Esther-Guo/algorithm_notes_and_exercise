// http://codeup.cn/problem.php?cid=100000575&pid=5

/*
大数int加法，注意是否会超出int范围。
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int a, b, c;
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			printf("Case #%d: ", i + 1);
			if (a/2.0 + b/2.0 > c/2.0) {
				printf("true\n");
			}
			else {
				printf("false\n");
			}
		}
	}
	return 0;
}