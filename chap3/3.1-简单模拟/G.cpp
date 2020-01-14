// http://codeup.cn/problem.php?cid=100000575&pid=6

/*
需要考虑的特殊情况：交错求和结果为0.
读题：每行结尾无多余空格.
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int num;
	int n;
	int flag = 0;
	int a[5] = { 0 };
	int index = 1;
	double sum = 0;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d", &num);
			if (num % 10 == 0) {
				a[0] += num;
			}
			else if (num % 5 == 1) {
				flag = 1; // 区别计算后结果为0与不存在满足条件的数字
				a[1] += index * num;
				index *= -1;
			}
			else if (num % 5 == 2) {
				a[2]++;
			}
			else if (num % 5 == 3) {
				sum += num;
				a[3]++;
			}
			else if (num % 5 == 4) {
				if (a[4] < num) a[4] = num;
			}
			else continue;
		}
		for (int j = 0; j < 5; j++) {
			if (j < 4) {
				if (j == 1 && flag && !a[1]) printf("0 ");
				else if (!a[j]) printf("N ");
				else if (j == 3) printf("%.1f ", sum / a[j]);
				else printf("%d ", a[j]);
			}
			else { // 行尾无多余空格
				if (!a[j]) printf("N\n");
				else printf("%d\n", a[j]);
			}
		}
		memset(a, 0, sizeof(a));
		index = 1;
		sum = 0;
		flag = 0;
	}
	return 0;
}