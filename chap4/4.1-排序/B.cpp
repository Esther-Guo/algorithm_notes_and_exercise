// http://codeup.cn/problem.php?cid=100000581&pid=1

/*
根据测试，如果最大数字有重复，只去掉一个即可。
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int a[1000] = { 0 };
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		printf("%d\n", a[n - 1]);
		a[n - 1] = NULL;
		if (n == 1) printf("-1");
		else {
			for (int i = 0; i < n-1; i++) {
				i ? printf(" %d", a[i]) : printf("%d", a[i]);
			}
		}
		printf("\n");
		
	}
	return 0;
}