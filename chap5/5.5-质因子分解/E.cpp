// http://codeup.cn/problem.php?cid=100000592&pid=4

/*

*/

#include <cstdio>
#include <cmath> 

int main() {
	int e[60]={0}, g[60]={0};
	int e_cnt=0, g_cnt=0;
	for (int k=2; k<=60; k++){
		int sqr = (int)sqrt(1.0*k);
		int sum = 1;
		for (int i=2;i<=sqr;i++){
			if (k%i == 0){
				if (i != k/i) sum += (i+k/i); 
				else sum += i; // 避免重复加
			}
		}
		if (sum == k) {
			e[e_cnt++] = k;
		}
		if (sum > k) {
			g[g_cnt++] = k;
		}
	}
	printf("E: ");
	for (int i=0;i<e_cnt;i++){
		printf("%d ", e[i]);
	}
	printf("G: ");
	for (int i=0;i<g_cnt;i++){
		printf("%d ", g[i]);
	}
	return 0;
}