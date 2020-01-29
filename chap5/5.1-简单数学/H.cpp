// http://codeup.cn/problem.php?cid=100000588&pid=7

/*

*/

#include <cstdio>


int main() {
	int m;
	scanf("%d", &m);
	while(m--){
		int n;
		scanf("%d", &n);
		int sum=0;
		if (n>=0){
			for (int i=n;i<=2*n;i++){
				sum+=i; 
			}
		}
		else{
			for(int i=2*n;i<=n;i++){
				sum+=i;
			}
		}
	
		printf("%d\n", sum);
	}
	return 0;
}