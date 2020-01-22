// http://codeup.cn/problem.php?cid=100000584&pid=0

/*
变量命名不要用可能是关键字的单词，比如time！！
本题应考虑优先选择右边界最小的区间（而非左边界最小）
*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int s, e;
}t[110];

bool cmp(node a, node b) {
	if (a.e == b.e) return a.s > b.s;
	else return a.e < b.e;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n) {
			for (int i = 0; i < n; i++) {
				scanf("%d %d", &t[i].s, &t[i].e);
			}
			sort(t, t + n, cmp);
			int ans = 1, chosen = 0;
			for (int i = 1; i < n; i++) {
				if (t[i].s >= t[chosen].e) {
					ans++;
					chosen = i;
				}
			}
			printf("%d\n", ans);
		}
		else break;
	}
	return 0;
}