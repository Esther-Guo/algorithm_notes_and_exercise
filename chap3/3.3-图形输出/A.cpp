// http://codeup.cn/problem.php?cid=100000577&pid=0

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>


int main() {
	int h;
	while (scanf("%d", &h) != EOF) {
		for (int i = 0; i < h; i++) {
				for (int m = 0; m < (2 * (h - i - 1)); m++) printf(" ");
				for (int n = 0; n < 2 * i + h; n++) printf("*");
				printf("\n");
			}
	}
	
	return 0;
}