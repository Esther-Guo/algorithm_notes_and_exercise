// http://codeup.cn/problem.php?cid=100000581&pid=3

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	char s[210];
	while (gets_s(s) != NULL) {
		int len = strlen(s);
		sort(s, s + len);
		printf("%s\n", s);
	}
	return 0;
}