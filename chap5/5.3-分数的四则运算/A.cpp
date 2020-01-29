// 尚未通过
// http://codeup.cn/problem.php?cid=100000590&pid=0

/*

*/

#include <cstdio>
#include <cmath>

int gcd(int a, int b){
	if (b==0) return a;
	else return gcd(b, a%b);
}

struct Fraction {
    int up, down; // 分子，分母
};

// 化简
Fraction reduction(Fraction result){
    if (result.down < 0) { // 对于负分数，统一令分子为负数
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) result.up = 1; // 对于分子为0的分数，统一令分母为1
    else { // 约分
        int d = gcd(fabs(result.up), fabs(result.down)); //求出最大公约数
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction addition(Fraction a, Fraction b){
	Fraction result;
	result.up = a.up*b.down + a.down*b.up;
	result.down = a.down*b.down;
	return result; 
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		if (n){
			if (n==1) {
				printf("1.00\n");
				continue;	
			}
			else {
				Fraction result, temp;
				result.up = 0;
				result.down = 1;
				for (int i=2; i<=n; i++){
					temp.up = 1;
					temp.down = i;
					for (int j=0; j<n-i+1; j++){
						result = addition(result, temp);	
					}
					result = reduction(result);
				}
				result.up *= 2;
				double ans = (double)result.up/result.down;
				ans += n;
				printf("%.2lf\n", ans);
			}
			
		}
		else break;
	}
	return 0;
}