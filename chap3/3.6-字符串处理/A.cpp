// http://codeup.cn/problem.php?cid=100000580&pid=0

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char s1[101], s2[101];
	char ans[201];
	int m;
	while (scanf("%s %s", s1, s2) != EOF) { 
        // 处理s1
		for (int i = 0; i < 100; i++) {
			if (s1[i] != '\0') ans[i] = s1[i];
			else { m = i; break; } // m keeps the value of i
		}
        // 处理s2
		int j = 0;
		for (; m < 200; m++) {
			if (s2[j] != '\0') { ans[m] = s2[j]; j++; }
			else break;
		}
        // print answer
		for (int k=0; k < m; k++) {
			printf("%c", ans[k]);
		}
		printf("\n");
	}
	return 0;
}