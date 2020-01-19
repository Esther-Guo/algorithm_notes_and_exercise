// http://codeup.cn/problem.php?cid=100000580&pid=7

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char a[100][25];
	int m;
	int n = 0;
	scanf("%d", &m);
	while (m--) {
		scanf("%s", a[n++]);
		if (n <= 4) {
			for (int i = 0; i < n; i++) {
				i ? printf(" %d=%s", i + 1, a[n - i - 1]) : printf("%d=%s", i + 1, a[n - i - 1]);
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				i ? printf(" %d=%s", i + 1, a[n - i - 1]) : printf("%d=%s", i + 1, a[n - i - 1]);
			}
		}
		printf("\n");
	}

	
	return 0;
}