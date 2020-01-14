// http://codeup.cn/problem.php?cid=100000575&pid=2

/*注意判断循环终止条件*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int a, b;
	int a_sum = 0, b_sum = 0;
	while (scanf("%d %d", &a, &b) != EOF) {
		while (a / 10) {
			a_sum += a % 10;
			a /= 10;
		}
		a_sum += a; //加上剩余的一位
		while (b / 10) {
			b_sum += b % 10;
			b /= 10;
		}
		b_sum += b;
		printf("%d\n", a_sum * b_sum);
		a_sum = b_sum = 0;
	}
	return 0;
}