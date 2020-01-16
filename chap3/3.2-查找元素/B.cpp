// http://codeup.cn/problem.php?cid=100000576&pid=1

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int n;
	int nums[200] = { 0 };
	int x;
	int j;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		scanf("%d", &x);
		for (j = 0; j < n; j++) {
			if (nums[j] == x) {
				printf("%d\n", j); 
				break;
			}
		}
		if (j == n) printf("-1\n");
		memset(nums, 0, sizeof(nums));
		j = 0;
	}
	return 0;
}