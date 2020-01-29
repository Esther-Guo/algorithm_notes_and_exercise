// http://codeup.cn/problem.php?cid=100000588&pid=12

/*

*/

#include <cstdio>
#include <cmath>


int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		int feet;
		scanf("%d", &feet);
		if (feet%2) {printf("0 0\n"); continue;}
		int feet_copy = feet; 
		int min = 0, max = 0;
		max = feet/2;
		while (feet){
			if (feet>=4) feet -= 4;
			else feet -= 2;
			min++;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}