// http://codeup.cn/problem.php?cid=100000580&pid=5

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char s[1000];
	int n = 0, m = 0;
	while (gets_s(s) != NULL) {
		for (int i = strlen(s)-1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	
	return 0;
}