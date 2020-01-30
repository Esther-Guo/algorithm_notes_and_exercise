// http://codeup.cn/problem.php?cid=100000592&pid=1

/*
same as A
*/

#include <cstdio>
#include <cmath> 

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		bool flag = false;
		for (int k=2; k<=n; k++){
			int sqr = (int)sqrt(1.0*k);
			int sum = 1;
			for (int i=2;i<=sqr;i++){
				if (k%i == 0){
					sum += (i+k/i);
				}
			}
			if (sum == k) {
				if (flag) printf(" %d", k);
				else {
					flag = true;
					printf("%d", k);
				}
			}
		}
		printf("\n");
	}
	return 0;
}