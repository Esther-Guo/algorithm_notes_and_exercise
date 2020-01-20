// http://codeup.cn/problem.php?cid=100000581&pid=4

/*
题目叙述有误，有多组测试数据而非只有一组 气死我啦:))
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int m;
	int matrix[10][10] = { 0 };
	int arr[21] = { 0 };
	while (scanf("%d", &m) != EOF) {
		for (int i = 0; i < m; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				scanf("%d", &matrix[i][j]);
				temp += matrix[i][j];
			}
			arr[i] = temp;
		}
		for (int i = 0; i < m; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				temp += matrix[j][i];
			}
			arr[m + i] = temp;
		}
		for (int i = 0; i < m; i++) {
			arr[2 * m] += matrix[i][i];
			arr[2 * m + 1] += matrix[i][m - i - 1];
		}
		sort(arr, arr + 2 * m + 2, cmp);
		for (int i = 0; i <= 2 * m + 1; i++) {
			i ? printf(" %d", arr[i]) : printf("%d", arr[i]);
		}
		printf("\n");
		memset(matrix, 0, sizeof(matrix));
		memset(arr, 0, sizeof(arr));
	}
	
	
	return 0;
}