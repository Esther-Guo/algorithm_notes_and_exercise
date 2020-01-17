// http://codeup.cn/problem.php?cid=100000579&pid=0

/*
出现int相加可能溢出的情况时，应将int直接定义为long long
*/

#include <cstdio>
#include <cstring>

int main() {
	int m;
	long long a, b;
	long long ans;
	while (scanf("%d", &m) != EOF) {
		if (m) {
			scanf("%lld %lld", &a, &b);
			ans = a + b;
            // 除基取余
			int arr[32] = { 0 }, index = 0;
			do {
				arr[index++] = ans % m;
				ans /= m;
			} while (ans);
			for (int i = index - 1; i >= 0; i--) {
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		else break;
	}
	
	return 0;
}