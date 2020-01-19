// http://codeup.cn/problem.php?cid=100000580&pid=7

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char s[260];
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			printf("NO\n");
			break;
		}
		if (i == len / 2 - 1) printf("YES\n");
	}
	return 0;
}