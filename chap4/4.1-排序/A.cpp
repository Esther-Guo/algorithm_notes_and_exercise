// http://codeup.cn/problem.php?cid=100000581&pid=0

#include <cstdio>
#include <algorithm> // keep in mind!

using namespace std; // keep in mind!

int main() {
	int n;
	int a[100] = { 0 };
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}