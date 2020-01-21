// http://codeup.cn/problem.php?cid=100000583&pid=1

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int fibonacci(int n){
	if (n==1 || n==2) return 1;
	else return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
	int m;
	scanf("%d", &m);
	while (m--){
		int n;
		scanf("%d", &n);
		int array[21] = {0};
		for (int i=0;i<2*n-2;i++){
			array[i+1] = fibonacci(i+1);
		}
		for (int i=1;i<=n;i++){
			for (int k = 0;k<2*(n-i);k++) printf(" ");
			for (int j=0;j<2*i-1;j++){
				printf("%d ", array[j]);
			}
			printf("\n");
		}
	}
	return 0;
}