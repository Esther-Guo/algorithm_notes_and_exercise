// http://codeup.cn/problem.php?cid=100000588&pid=10

/*

*/

#include <cstdio>
#include <cmath>


int main() {
	int n,x;
	while(scanf("%d %d", &x, &n) != EOF){
		double ans = x;
		for (int i=0;i<n;i++){
			ans = ans*2.0/3.0 + x/(3*ans*ans);
		}
	
		printf("%.6lf\n", ans);
	}
	return 0;
}