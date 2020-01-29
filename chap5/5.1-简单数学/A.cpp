// http://codeup.cn/problem.php?cid=100000588&pid=0

/*
注意使用pow()尽量保证参数为double类型，且结果也为double。如需转为int，须谨慎操作。
*/

#include <cstdio>
#include <cmath>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int sqr = n * n;
		int power = (n >= 10) ? (int)pow(10, 2) : (int)pow(10, 1);
		int ans = (sqr - n) % power;
		if (ans == 0) printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}