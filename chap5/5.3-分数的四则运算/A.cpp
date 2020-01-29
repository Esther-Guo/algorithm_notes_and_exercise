// http://codeup.cn/problem.php?cid=100000590&pid=0

/*
使用书中方法会出现超时以及大数范围超出long long的问题……
*/

#include <cstdio>

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		if (n){
			if (n==1) {
				printf("1.00\n");
				continue;	
			}
			else {
				double result=0;
				for (int i=2; i<=n; i++){
					result += (double)(n-i+1)/i;	
				}
				result *= 2;
				result += n;
				printf("%.2lf\n", result);
			}
			
		}
		else break;
	}
	return 0;
}