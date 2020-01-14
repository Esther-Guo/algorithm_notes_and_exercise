// http://codeup.cn/problem.php?cid=100000575&pid=3

/**/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int n;
	int num;
	int odd = 0, even = 0;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d", &num);
			if (num % 2) odd++;
			else even++;
		}
		if (odd > even) printf("YES\n");
		else printf("NO\n");
		odd = even = 0;
	}
	return 0;
}