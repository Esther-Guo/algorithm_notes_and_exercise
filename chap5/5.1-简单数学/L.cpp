// http://codeup.cn/problem.php?cid=100000588&pid=11

/*

*/

#include <cstdio>
#include <cmath>


int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		int sum = 0;
		for (int i=1;i<=n;i++){
			if (i%7 && i%10!=7 && (i-i%10)/10!=7) sum += i*i;
		}
		printf("%d\n", sum);
	}
	return 0;
}