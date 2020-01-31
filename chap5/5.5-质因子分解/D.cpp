// http://codeup.cn/problem.php?cid=100000592&pid=3

/*

*/

#include <cstdio>
#include <cmath> 

const int maxn = 100000;
int prime[maxn], pNum = 0;
bool p[maxn] = { 0 };
struct factorial {
	int x, cnt;
}fac[10];

bool isPrime(int n) {
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void findPrime() {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j += i) {
				p[j] = true;
			}

		}
	}
}

int count_fac(int n){
	int sqr = (int)sqrt(1.0 * n);
	int num = 0;
	for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
		if (n % prime[i] == 0) {
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while (n % prime[i] == 0) {
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
	}
	if (n != 1) {
		fac[num].x = n;
		fac[num++].cnt = 1;
	}
	int sum = 1;
	for (int i = 0; i < num; i++) {
			sum *= (fac[i].cnt+1);
	}
	return sum;
}

int main() {
	findPrime();
	int n;
	while (scanf("%d", &n) != EOF) {
		if(n) {
			int nums[1010] = {0};
			for (int i = 0; i < n; i++) {
				scanf("%d", &nums[i]);
				nums[i] = count_fac(nums[i]);
			}
			for (int i = 0; i < n; i++) {
				printf("%d\n", nums[i]);
			}
		} 
		else break;
		
		
	}
	return 0;
}