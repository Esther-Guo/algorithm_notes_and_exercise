// http://codeup.cn/problem.php?cid=100000588&pid=2

/*
因为100只已定，所以z是由xy决定的。
遍历j时上限应设为100-i，否则会出错。
1/3的处理可以有多种方式，可采取代码中写法或是 3*5*i+3*3*j+k <= 3*n 将问题简化。 
*/

#include <cstdio>
#include <cmath>

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		if (n <= 33) continue;
		
		for (int i=0;i<=100;i++){
			for (int j=0;j<=100-i;j++){
				int k=100-j-i;
				if (5*i+3*j+k/3.0<=n){
					printf("x=%d,y=%d,z=%d\n", i, j, k);
				}
			}
		}
	}
	return 0;
}