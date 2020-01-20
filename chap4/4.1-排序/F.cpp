// http://codeup.cn/problem.php?cid=100000581&pid=5

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct mouse {
	int weight;
	char color[20];
}mice[110];

bool cmp(mouse a, mouse b) {
	return a.weight > b.weight;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %s", &mice[i].weight, mice[i].color);
		}
		sort(mice, mice + n, cmp);
		for (int i = 0; i < n; i++) {
			printf("%s\n", mice[i].color);
		}
	}
	return 0;
}