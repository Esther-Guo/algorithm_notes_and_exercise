// http://codeup.cn/problem.php?cid=100000575&pid=8

/*
注意获取字符时对回车及空格的控制
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	int n;
	char a, b;
	int a_nums[3] = { 0 }, b_nums[3] = { 0 };
	int a_win[3] = { 0 }, b_win[3] = { 0 }; // B, C, J
	while (scanf("%d", &n) != EOF) {
		getchar(); // 吸收回车
		while (n--) {
			a = getchar();
			getchar(); // 吸收空格
			b = getchar(); 
			getchar(); // 吸收回车
			if (a == 'B') {
				if (b == 'B') { a_nums[1]++; b_nums[1]++; }
				else if (b == 'C') { a_nums[0]++; b_nums[2]++; a_win[0]++; }
				else { a_nums[2]++; b_nums[0]++; b_win[2]++; }
			}
			else if (a == 'C') {
				if (b == 'B') { a_nums[2]++; b_nums[0]++; b_win[0]++; }
				else if (b == 'C') { a_nums[1]++; b_nums[1]++; }
				else { a_nums[0]++; b_nums[2]++; a_win[1]++; }
			}
			else {
				if (b == 'B') { a_nums[0]++; b_nums[2]++; a_win[2]++; }
				else if (b == 'C') { a_nums[2]++; b_nums[0]++; b_win[1]++; }
				else { a_nums[1]++; b_nums[1]++; }
			}
		}
		printf("%d %d %d\n", a_nums[0], a_nums[1], a_nums[2]);
		printf("%d %d %d\n", b_nums[0], b_nums[1], b_nums[2]);
		if (a_win[0] >= a_win[1]) {
			if (a_win[0] >= a_win[2]) printf("B ");
			else printf("J ");
		}
		else {
			if (a_win[1] >= a_win[2]) printf("C ");
			else printf("J ");
		}
		if (b_win[0] >= b_win[1]) {
			if (b_win[0] >= b_win[2]) printf("B\n");
			else printf("J\n");
		}
		else {
			if (b_win[1] >= b_win[2]) printf("C\n");
			else printf("J\n");
		}
		memset(a_nums, 0, sizeof(a_nums));
		memset(b_nums, 0, sizeof(b_nums));
		memset(a_win, 0, sizeof(a_win));
		memset(b_win, 0, sizeof(b_win));
	}
	return 0;
}