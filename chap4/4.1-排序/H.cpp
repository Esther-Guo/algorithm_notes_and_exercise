// http://codeup.cn/problem.php?cid=100000581&pid=7

/*
使用memset()一定要写#include <cstring>!!!!
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int num[10];
	int odd[10] = { 0 };
	int even[10] = { 0 };
	int od = 0;
	int ev = 0;
	while (scanf("%d", &num[0]) != EOF) {
		for (int i = 1; i < 10; i++) {
			scanf("%d", &num[i]);
		}
		for (int i = 0; i < 10; i++) {
			if (num[i] % 2 == 0) even[ev++] = num[i];
			else odd[od++] = num[i];
		}
		sort(odd, odd + od, cmp);
		sort(even, even + ev);
		for (int i = 0; i < od; i++) {
			printf("%d ", odd[i]);
		}
		for (int i = 0; i < ev; i++) {
			printf("%d ", even[i]);
		}
		printf("\n");
		memset(odd, 0, sizeof(odd));
		memset(even, 0, sizeof(even));
		od = ev = 0;
	}
	return 0;
}