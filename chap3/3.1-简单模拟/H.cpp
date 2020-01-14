// http://codeup.cn/problem.php?cid=100000575&pid=7

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	long long a, b;
	int da, db;
	int count_a = 0, count_b = 0;
	long long pa = 0, pb = 0;
	while (scanf("%lld %d %lld %d", &a, &da, &b, &db) != EOF) {
		while (a / 10) {
			if (a % 10 == da) count_a++;
			a /= 10;
		}
		if (a == da) count_a++;
		while (b / 10) {
			if (b % 10 == db) count_b++;
			b /= 10;
		}
		if (b == db) count_b++;
		int i = 0;
		while (count_a--) {
			pa += da * pow(10, i);
			i++; // 记得递增
		}
		i = 0;
		while (count_b--) {
			pb += db * pow(10, i);
			i++;
		}
		printf("%d\n", pa + pb);
		count_a = count_b = 0;
		pa = pb = 0;
	}
	return 0;
}