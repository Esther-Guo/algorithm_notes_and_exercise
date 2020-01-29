// http://codeup.cn/problem.php?cid=100000588&pid=9

/*

*/

#include <cstdio>
#include <cmath>


int main() {
	int m;
	scanf("%d", &m);
	while(m--){
		int n,x;
		scanf("%d", &n);
		int a[11]={0};
		for (int i=0;i<n+1;i++){
			scanf("%d", &a[i]);	
		}
		scanf("%d", &x);
		int sum = 0;
		for (int i=0;i<n+1;i++){
			sum += (int)(a[i] * pow((double)x,i));	
		}
	
		printf("%d\n", sum);
	}
	return 0;
}