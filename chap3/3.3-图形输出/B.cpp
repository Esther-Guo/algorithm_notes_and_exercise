// http://codeup.cn/problem.php?cid=100000577&pid=1

/*
重点在于理解题目中的算式含义
*/

#include <cstdio>
#include <cstring>
#include <cmath>


int main() {
	char str[100];
	int len;
	while (scanf("%s", str) != EOF) {
		len = strlen(str);
		for (int i = 0; i < (len + 2) / 3 - 1; i++) {
			printf("%c", str[i]);
			for (int j = 0; j < ((len+2) - 2 * ((len + 2) / 3)) - 2; j++) {
				printf(" ");
			}
			printf("%c\n", str[len - i - 1]);
		}
		for (int i = (len + 2) / 3 - 1; i < (len - ((len + 2) / 3 - 1)); i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	
	return 0;
}