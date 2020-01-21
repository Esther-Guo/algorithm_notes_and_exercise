// http://codeup.cn/problem.php?cid=100000583&pid=0

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int choco(int n){
	if (n==1) return 1;
	if (n==2) return 2;
	else return choco(n-1)+choco(n-2);
}

int main() {
	int m;
	while (scanf("%d", &m) != EOF){
		int plans;
		plans = choco(m);
		printf("%d\n", plans);
	}
	return 0;
}