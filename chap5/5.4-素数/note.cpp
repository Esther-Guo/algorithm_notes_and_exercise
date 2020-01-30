// 1既不是质数也不是合数
// 100000以内的素数个数为9592个。做题应注意区间范围。

// 快速判断正整数n是否为素数 O(sqrt(n))
#include <cmath>
bool isPrime(int n){
    if (n<=1) return false;
    int sqr = (int)sqrt(1.0*n); // 根号n向下取整
    for (int i=2;i<=sqr;i++){ // 若n较小，也可以用(i=0;i*i<=n;i++)
        if (n%i==0) return false;
    }
    return true;
}

// 得到1~n范围内素数表 (n<10^5) O(n*sqrt(n))
const int maxn = 101;
int prime[maxn], pNum = 0; // 存放素数的数组，素数个数
bool p[maxn] = {0}; // p[i] == true 表示i是素数
void findPrime() {
    for (int i=1; i< maxn; i++){
        if (isPrime(i) == true) {
            prime[pNum++] = i;
            p[i] = true;
        }
    }
}

// n>10^5, 可采用素数筛法 O(nloglogn)
// 思想：从小到大枚举所有数，对于每一个素数，筛去它所有的倍数
const int maxn = 101;
int prime[maxn], pNum = 0; // 存放素数的数组，素数个数
bool p[maxn] = {0}; // 默认全部是素数。p[i] == **false** 表示i是素数
void findPrime() {
    for (int i=2; i< maxn; i++){ // 已知2是素数
        if (p[i] == false) { // i是素数
            prime[pNum++] = i;
            for (int j = i+i; j<maxn; j+=i)
                p[j] = true; // 标记i的倍数为合数
        }
    }
}