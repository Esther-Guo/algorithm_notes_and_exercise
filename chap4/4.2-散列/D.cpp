// http://codeup.cn/problem.php?cid=100000582&pid=3

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	char s1[10010], s2[10010];
	while (gets(s1)!=NULL) {
		gets(s2);
		int s1_len = strlen(s1);
		int s2_len = strlen(s2);
		int hash[127] = {0};
		for (int i=0;i<s2_len;i++){
			hash[s2[i]] = 1;
		}
		for (int i=0;i<s1_len;i++){
			if (!hash[s1[i]]) printf("%c", s1[i]);
		}
		printf("\n");
	}
	return 0;
}