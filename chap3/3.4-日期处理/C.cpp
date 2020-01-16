// http://codeup.cn/problem.php?cid=100000578&pid=2

/*

*/

#include <cstdio>
#include <cstring>

// 第二维用于存储闰年每月对应天数
int month[13][2] = { 
	{0,0}, {31,31}, {28,29}, {31,31}, {30,30}, {31,31},
	{30,30}, {31,31}, {31,31}, {30,30}, {31,31}, {30,30}, {31,31} };

// 判断闰年
bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	int year, days;
	int mon, day;
	while (scanf("%d %d", &year, &days) != EOF) {
		if (days <= 58) {
			if (days <= 31) { mon = 1; day = days; }
			else { mon = 2; day = days - 31; }
		}
		else {
			int i = 1;
			while (days > month[i][isLeap(year)]) {
				days -= month[i][isLeap(year)];
				i++;
			}
			mon = i;
			day = days;
		}
		printf("%04d-%02d-%02d\n", year, mon, day);
	}
	
	return 0;
}