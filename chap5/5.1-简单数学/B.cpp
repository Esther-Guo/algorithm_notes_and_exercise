// http://codeup.cn/problem.php?cid=100000588&pid=1

/*

*/

#include <cstdio>
#include <cmath>

int main() {
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if ((i * 1000 + j * 100 + k * 10 + l) * 9 == (l * 1000 + k * 100 + j * 10 + i)) printf("%d\n", i * 1000 + j * 100 + k * 10 + l);
				}
			}
		}
	}
	return 0;
}