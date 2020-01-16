// http://codeup.cn/problem.php?cid=100000578&pid=0

/*
经典日期计算问题
*/

#include <cstdio>

// 第二维用于存储闰年每月对应天数
int month[13][2] = { 
	{0,0}, {31,31}, {28,29}, {31,31}, {30,30}, {31,31},
	{30,30}, {31,31}, {31,31}, {30,30}, {31,31}, {30,30}, {31,31} };

// 判断闰年
bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	int t1,t2;
	int y1, m1, d1, y2, m2, d2;
	while (scanf("%d %d", &t1, &t2) != EOF) {
		// 若t1>t2则交换位置
		if (t1 > t2) {
			int temp = t1;
			t1 = t2;
			t2 = temp;
		}
		// 获取年月日
		y1 = t1 / 10000; m1 = t1 % 10000 / 100; d1 = t1 % 100;
		y2 = t2 / 10000; m2 = t2 % 10000 / 100; d2 = t2 % 100;
		int ans = 1;
		while (y1 < y2 || m1 < m2 || d1 < d2) {
			d1++; // 不断使t1自增直到和t2相同
			if (d1 == month[m1][isLeap(y1)] + 1) { // 数满一月后进位
				m1++;
				d1 = 1;
			}
			if (m1 == 13) { // 数满一年后进位
				y1++;
				m1 = 1;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}