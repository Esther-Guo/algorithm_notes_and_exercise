// http://codeup.cn/problem.php?cid=100000586&pid=2/3

/*

*/

#include <cstdio>

int partition(int* A, int left, int right){
	int temp = A[left];
	while (left < right){
		while(left<right && temp < A[right]) right--;
		A[left] = A[right];
		while(left<right && temp >= A[left]) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void quickSort(int* A, int left, int right){
	if(left<right){
		int pos = partition(A, left, right);
		quickSort(A, left, pos-1);
		quickSort(A, pos+1, right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int nums[5010];
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]); 
	}
	quickSort(nums, 0, n-1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", nums[i]); 
	}
	return 0;
}