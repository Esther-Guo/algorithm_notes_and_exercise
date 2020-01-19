// http://codeup.cn/problem.php?cid=100000580&pid=3

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char s[200];
	char a[150], b[150];
	char ans[100][150];
	while (gets_s(s) != NULL) {
		scanf("%s", a);
		scanf("%s", b);
		int n = 0, k = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] != ' ') {
				ans[n][k] = s[i];
				k++;
			}
			else {
				ans[n][k] = '\0';
				n++; 
				k = 0;
			}
		}
		ans[n][k] = '\0';
		for (int j = 0; j <= n; j++) {
			if (!strcmp(ans[j], a)) strcpy(ans[j], b);
		}
		for (int j = 0; j <= n; j++) {
			printf("%s", ans[j]);
			if (j < n) printf(" ");
		}
		getchar(); // 吸收回车
		printf("\n");
	}
	
	return 0;
}