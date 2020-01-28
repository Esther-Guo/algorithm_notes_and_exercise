// http://codeup.cn/problem.php?cid=100000586&pid=1

/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

void merge(int* A, int l1, int r1, int l2, int r2){
	int i = l1, j = l2;
	int temp[100010], index=0;
	while (i <= r1 && j <= r2){
		if (A[i] <= A[j]) temp[index++] = A[i++];
		else temp[index++] = A[j++];
	}
	while(i<=r1) temp[index++] = A[i++];
	while(j<=r2) temp[index++] = A[j++];
	for (int i=0;i<index;i++){
		A[l1+i] = temp[i];
	}
}

void mergeSort(int* A, int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid+1, right);
		merge(A, left, mid, mid+1, right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int m;
		scanf("%d", &m);
		int nums[100010];
		for (int i = 0; i < m; i++) {
			scanf("%d", &nums[i]); 
		}
		mergeSort(nums, 0, m-1);
		for (int i = 0; i < m; i++) {
			printf("%d\n", nums[i]); 
		}
	}
	return 0;
}