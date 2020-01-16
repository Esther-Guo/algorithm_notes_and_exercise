// http://codeup.cn/problem.php?cid=100000577&pid=3

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>


int main() {
	int n; // 2n-1层
	while (scanf("%d", &n) != EOF) {
        // 前n层
		for (int i = n; i > 0; i--) {
			for (int k = 0; k < n - i; k++) printf(" ");
			for (int j = 0; j < i; j++) printf("* ");
			printf("\n");
		}
        // 后n-1层
		for (int i = 1; i < n; i++) {
			for (int k = n - i - 1; k > 0; k--) printf(" ");
			for (int j = -1; j < i; j++) printf("* ");
			printf("\n");
		}
	}
	
	return 0;
}