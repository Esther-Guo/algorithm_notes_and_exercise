// http://codeup.cn/problem.php?cid=100000580&pid=4

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char c,a;
	char s[1000];
	char ans[1000];
	int n = 0, m = 0;
	while (gets_s(s) != NULL) {
		scanf("%c", &a);
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] != a) ans[m++] = s[i];
		}
		for (int j = 0; j < m; j++) {
			printf("%c", ans[j]);
		}
		printf("\n");
		getchar(); // 吸收换行
		m = 0;
	}
	
	return 0;
}