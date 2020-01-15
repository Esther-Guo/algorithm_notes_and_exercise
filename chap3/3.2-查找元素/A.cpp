// http://codeup.cn/problem.php?cid=100000576&pid=0

/*
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int n;
	int grade[1000] = { 0 };
	int wanted;
	int count = 0;
	while (scanf("%d", &n) != EOF) {
		if (!n) break;
		for (int i=0;i<n;i++) {
			scanf("%d", &grade[i]);
		}
		scanf("%d", &wanted);
		for (int i = 0; i < n; i++) {
			if (grade[i] == wanted) {
				count++;
			}
		}
		printf("%d\n", count);
		memset(grade, 0, sizeof(grade));
		count = 0;
	}
	return 0;
}