// http://codeup.cn/problem.php?cid=100000591&pid=1

/*

*/

#include <cstdio>
#include <cmath> 

const int maxn = 105000;
int prime[maxn], pNum=0;
bool p[maxn] = {0};

bool isPrime(int n){
	if (n<=1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i=2; i <= sqr; i++){
		if (n % i==0) return false;
	}
	return true;
}

void findPrime(int n){
	for (int i=2; i<maxn; i++){
		if (p[i] == false){
			prime[pNum++] = i;
			if (pNum >= n) break;
			for (int j=i+i; j<maxn; j += i){
				p[j] = true;
			}
			
		}
	}
}

int main() {
	
	int n;
	while(scanf("%d", &n) != EOF){
		findPrime(n);
		printf("%d\n", prime[n-1]);
		pNum = 0;
	}
	return 0;
}