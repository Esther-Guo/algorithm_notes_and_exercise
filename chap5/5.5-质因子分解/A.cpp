// http://codeup.cn/problem.php?cid=100000592&pid=0

/*
用教材给的方法反而容易把自己带坑里…… 
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
					if (i != k/i) sum += (i+k/i); 
					else sum += i; // 避免重复加
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