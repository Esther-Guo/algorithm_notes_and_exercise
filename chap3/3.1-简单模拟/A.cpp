// http://codeup.cn/problem.php?cid=100000575&pid=0

/*对大数组赋初值为0之外的值，使用memset赋-1*/

#include <cstdio>
#include <cstring>
const int MAX = 10000;
int trees[MAX];

int main() {
	int l, m;
	int a, b;
	int count = 0;
	memset(trees, -1, sizeof(trees));
	while (scanf("%d %d", &l, &m) != EOF) {
		if (l == 0 && m == 0) break;
		else {
			while (m--) {
				scanf("%d %d", &a, &b);
				for (int i = a; i < b + 1; i++) {
					trees[i] = 0;
				}
			}
			for (int j = 0; j < l + 1; j++) {
				if (trees[j]) count++;
			}
			printf("%d\n", count);
			memset(trees, -1, sizeof(trees));
			count = 0;
		}
	}
	
	
	return 0;
}