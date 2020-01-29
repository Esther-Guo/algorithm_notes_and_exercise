// http://codeup.cn/problem.php?cid=100000589&pid=0

/*

*/

#include <cstdio>

int GCD(int a, int b){
	if (b == 0)  return a;
	else return GCD(b, a%b);
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		int m;
		scanf("%d", &m);
		int a, b;
		for (int i=0;i<m;i++){
			if (i==0) scanf("%d", &a); // 第一个数
			else {
				scanf("%d", &b); // 下一个数
				int gcd = GCD(a, b); 
				a = a/gcd*b; // 求出最小公倍并赋给a
			}
		}
		
		printf("%d\n", a);
	}
	return 0;
}