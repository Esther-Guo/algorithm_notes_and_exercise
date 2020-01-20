// http://codeup.cn/problem.php?cid=100000581&pid=6

/*
注意条件判断是否取平均不要写反。
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int arr[10010] = { 0 };
	int median;
	while (scanf("%d", &n) != EOF) {
		if (n) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &arr[i]);
			}
			sort(arr, arr + n);
			if (n % 2 == 0) median = (arr[n / 2] + arr[n / 2 - 1]) / 2;
			else median = arr[n / 2];
			printf("%d\n", median);
			memset(arr, 0, sizeof(arr));
		}
		else break;
		
	}
	return 0;
}