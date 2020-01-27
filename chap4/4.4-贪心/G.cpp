// http://codeup.cn/problem.php?cid=100000584&pid=6

/*
注意审题，共有5种面值。
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	
	while (scanf("%d", &n) != EOF) {
		int cash[5] = {0};
		while(n){
			if (n>=50) {
				cash[0]++;
				n -= 50;
			}
			else if (n>=20) {
				cash[1]++;
				n -= 20;	
			}
			else if (n>=10) {
				cash[2]++;	
				n -= 10;
			}
			else if (n>=5) {
				cash[3]++;
				n -= 5;	
			}
			else {
				cash[4] += n;
				break;
			}
		}
		int flag = 0; // 是否输出+ 
		if (cash[0]) {
			printf("50*%d", cash[0]);
			flag = 1;	
		}
		if (cash[1]){
			if (flag) {
				printf("+20*%d", cash[1]);
			}
			else {
				printf("20*%d", cash[1]);
				flag = 1;
			}
		}
		if (cash[2]){
			if (flag) {
				printf("+10*%d", cash[2]);
			}
			else {
				printf("10*%d", cash[2]);
				flag = 1;
			}
		}
		if (cash[3]){
			if (flag) {
				printf("+5*%d", cash[3]);
			}
			else {
				printf("5*%d", cash[3]);
				flag = 1;
			}
		}
		if (cash[4]){
			if (flag) {
				printf("+1*%d", cash[4]);
			}
			else {
				printf("1*%d", cash[4]);
			}
		}
		printf("\n");
	}
	return 0;
}