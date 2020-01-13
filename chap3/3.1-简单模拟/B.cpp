// http://codeup.cn/problem.php?cid=100000575&pid=1

/*字符‘4’转数字4，ASCII减去48*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	char a[15], b[15];
	int a_len, b_len;
	int x = 0, y = 0;
	int n = 0;
	while (scanf("%s %s", a, b) != EOF) {
		a_len = strlen(a);
		b_len = strlen(b);
		while (a_len--) {
			if (a[a_len] == '-') {
				x *= -1;
				break;
			}
			if (a[a_len] == ',') {
				continue;
			}
			else {
				x += (a[a_len]-48) * pow(10, n);
				n++;
			}
		}
		n = 0; //初始化
		while (b_len--) {
			if (b[b_len] == '-') {
				y *= -1;
				break;
			}
			if (b[b_len] == ',') {
				continue;
			}
			else {
				y += (b[b_len]-48) * pow(10, n);
				n++;
			}
		}
		printf("%d\n", x + y);
		// 切记初始化
		x = y = 0;
		n = 0;
	}
	return 0;
}