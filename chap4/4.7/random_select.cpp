// find the k-th largest num

// http://codeup.cn/problem.php?cid=100000586&pid=2

/*

*/

#include <cstdio>

int partition(int* A, int left, int right){
	int temp = A[left]; // 以A[left]为主元将数组分成左右两部分，大数在左，小数在右
	while (left < right){
		while(left<right && temp > A[right]) right--;
		A[left] = A[right];
		while(left<right && temp <= A[left]) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

int randomSelect(int* A, int left, int right, int k){
	if(left==right) return A[left];
	int p = partition(A, left, right); // 主元最后在数组中的下标
	int M = p-left+1; // 主元是数组中第M大的数
	if (k == M) return A[p]; // 如果k==M则返回当前主元
	if (k<M) return randomSelect(A, left, p-1, k); // k<M则应去左半部分（大）找
	else return randomSelect(A, p+1, right, k-M); // k>M则应去右半部分（小）找
}

int main() {
	int n,k;
	while(scanf("%d %d", &n, &k) != EOF){
		int nums[100010];
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]); 
		}
		int num = randomSelect(nums, 0, n-1, k);
		printf("%d\n", num);
	}
	return 0;
}