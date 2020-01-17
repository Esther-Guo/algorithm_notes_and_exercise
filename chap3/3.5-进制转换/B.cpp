// http://codeup.cn/problem.php?cid=100000579&pid=1

/*
因为涉及>10进制数字，应使用字符串存储数据。
*/

#include <cstdio>
#include <cstring>

int main() {
	int a, b;
	char num[32];
	while (scanf("%d %s %d", &a, num, &b) != EOF) {
		int len = strlen(num);
		long long dec = 0;
		int product = 1;
		// 转为十进制数
		if (a <= 10) {
			for (int i = len - 1; i >= 0; i--) {
				dec += product * (num[i] - 48);
				product *= a;
			}
		}
		else {
			for (int i = len - 1; i >= 0; i--) {
				int temp;
				switch (num[i]) {
					case 'a': temp = 10; break;
					case 'A': temp = 10; break;
					case 'b': temp = 11; break;
					case 'B': temp = 11; break;
					case 'c': temp = 12; break;
					case 'C': temp = 12; break;
					case 'd': temp = 13; break;
					case 'D': temp = 13; break;
					case 'e': temp = 14; break;
					case 'E': temp = 14; break;
					case 'f': temp = 15; break;
					case 'F': temp = 15; break;
					default: temp = num[i] - 48;
				}
				dec += product * temp;
				product *= a;
			}
		}
		// 转为b进制数
		int n;
		char ans[32];
		int index = 0;
		do {
			n = dec % b;
			switch (n) {
			case 10: ans[index++] = 'A'; break;
			case 11: ans[index++] = 'B'; break;
			case 12: ans[index++] = 'C'; break;
			case 13: ans[index++] = 'D'; break;
			case 14: ans[index++] = 'E'; break;
			case 15: ans[index++] = 'F'; break;
			default: ans[index++] = n+48;
			}
			dec /= b;
		} while (dec != 0);
		for (int i = index - 1; i >= 0; i--) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}