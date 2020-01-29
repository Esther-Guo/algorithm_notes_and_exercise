// http://codeup.cn/problem.php?cid=100000588&pid=6

/*
same as D
*/

#include <cstdio>
#include <cmath>

int main() {
	int a, b;
	for (a=0;a<=5;a++) {
		for (b=0;b<=5;b++) {
			if ((a+b)*100+(b+1)*10+2*1 == 532) printf("%d %d %d\n", a, b, 1);
			if ((a+b)*100+(b+6)*10+2*6 == 532) printf("%d %d %d\n", a, b, 6);
		}
	}
	return 0;
}