// insertSort

#include <cstdio>

void insertSort(int a[], int n) {
	for (int i = 1; i < n; i++) { // n-1次插入
		int temp = a[i]; // 待插入元素
		int j = i; // 标记插入位置
		while (j > 0 && temp < a[j - 1]) {
			a[j] = a[j - 1]; // a[j-1]后移一位
			j--;
		}
		a[j] = temp; // 插入元素
	}
}

int main() {
	int a[5] = { 4, 8, 0, 9, 7 };
	insertSort(a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}