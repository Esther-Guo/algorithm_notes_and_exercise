// http://codeup.cn/problem.php?cid=100000580&pid=6

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char a[55], b[55];
	int m;
	scanf("%d", &m);
	getchar();
	while (m--) {
		scanf("%s", a);
		scanf("%s", b);
		if (strlen(a) == strlen(b)) printf("%s is equal long to %s\n", a, b);
		else if (strlen(a) > strlen(b)) printf("%s is longer than %s\n", a, b);
		else printf("%s is shorter than %s\n", a, b);
	}
	
	return 0;
}