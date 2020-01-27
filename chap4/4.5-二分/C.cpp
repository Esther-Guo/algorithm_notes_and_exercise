// http://codeup.cn/problem.php?cid=100000585&pid=2

/*
用二分一定首先保证数组有序！
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int binary_search(int* nums, int num, int n){
	int left = 0, right = n-1;
	while (left <= right){
		int mid = (left+right)/2;
		if (nums[mid] == num) return 1;
		else if (nums[mid] > num) right = mid-1;
		else left = mid+1;
	}
	if (left > right) return 0;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int nums[110];
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]); 
		}
		sort(nums, nums+n);
		int m, arr[110];
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &arr[i]); 
			if (binary_search(nums, arr[i], n)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}