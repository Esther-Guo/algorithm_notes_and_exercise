// http://codeup.cn/problem.php?cid=100000585&pid=0

/*
数据并非有序且数据量较小，不适合二分 
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	double nums[210];
	double item;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf", &nums[i]); 
		}
		scanf("%lf", &item);
		for (int i=0;i<n;i++){
			if (nums[i] == item) {printf("%d\n", i); break;}
			if (i == n-1) printf("-1\n");
		}
	}
	return 0;
}