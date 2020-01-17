// http://codeup.cn/problem.php?cid=100000579&pid=3

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	int num;
	int ans[20];
	while (scanf("%d", &num) != EOF) { 
		int n = 0;
		do {
			ans[n++] = num % 8;
			num /= 8;
		} while (num);
		for (int i = n-1; i >= 0; i--) {
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}