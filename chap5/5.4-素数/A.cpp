// http://codeup.cn/problem.php?cid=100000591&pid=0

/*

*/

#include <cstdio>
#include <cmath> 

const int maxn = 10001;
int prime[maxn], pNum=0;

bool isPrime(int n){
	if (n<=1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i=2; i <= sqr; i++){
		if (n % i==0) return false;
	}
	return true;
}

void findPrime(){
	for (int i=1; i<maxn; i++){
		if (isPrime(i)){
			prime[pNum++] = i;
		}
	}
}

int main() {
	findPrime();
	int n;
	while(scanf("%d", &n) != EOF){
		int i=0;
		bool flag = false;
		while (prime[i]<n) {
			if (prime[i]%10==1){
				flag? printf(" %d", prime[i]):printf("%d", prime[i]);
				flag = true;
			}
			i++;
		}
		if (!flag) printf("-1");
		printf("\n");
	}
	return 0;
}