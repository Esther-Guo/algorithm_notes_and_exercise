// http://codeup.cn/problem.php?cid=100000580&pid=1

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	char s[101];
	while (gets_s(s)) { 
		int flag = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '\0' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == ' ') flag = 1;
			// must be the initial letter or letter before empty character and should be one of the alphabets.
			else if ((flag || !i)&&(s[i]>=97 && s[i]<=122)) { s[i] -= 32; flag = 0; } 
			else { flag = 0; } 
		}
		for (int k=0; k < strlen(s); k++) {
			printf("%c", s[k]);
		}
		printf("\n");
	}
	return 0;
}