// selectSort

#include <cstdio>

void selectSort(int a[], int n) {
	for (int i = 0; i < n; i++) { // n趟比较
		int k = i; // k记录当前最小
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[k]) k = j;
		}
		// swap a[i] & a[k]
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}

int main() {
	int a[5] = { 4, 8, 0, 9, 7 };
	selectSort(a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}