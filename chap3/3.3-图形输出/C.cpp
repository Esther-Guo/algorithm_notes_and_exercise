// http://codeup.cn/problem.php?cid=100000577&pid=2

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>


int main() {
	int m, h;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			scanf("%d", &h);
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < h - i - 1; j++) printf(" ");
				for (int k = 0; k < h + i * 2; k++) printf("*");
				for (int j = 0; j < h - i - 1; j++) printf(" ");
				printf("\n");
			}
			
		}
	}
	
	return 0;
}