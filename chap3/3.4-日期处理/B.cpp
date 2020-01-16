// http://codeup.cn/problem.php?cid=100000578&pid=1

/*

*/

#include <cstdio>
#include <cstring>

char months[][20] = { 
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December" };

char week[][20] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

// 第二维用于存储闰年每月对应天数
int month[13][2] = { 
	{0,0}, {31,31}, {28,29}, {31,31}, {30,30}, {31,31},
	{30,30}, {31,31}, {31,31}, {30,30}, {31,31}, {30,30}, {31,31} };

// 判断闰年
bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	char mon[20];
	int y, m, d;
	while (scanf("%d %s %d", &d, mon, &y) != EOF) {
		for (int i = 0; i < 12; i++) {
			if (!strcmp(mon, months[i])) { m = i + 1; break; }
		}
		int ans = 0;
		int y1 = 1000, m1 = 1, d1 = 1; // Wednesday
		while (y1 < y || m1 < m || d1 < d) {
			d1++;
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
		ans = (ans+2) % 7 ;
		printf("%s\n", week[ans]);
	}
	
	return 0;
}