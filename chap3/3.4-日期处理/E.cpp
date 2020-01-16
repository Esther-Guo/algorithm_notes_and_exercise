// http://codeup.cn/problem.php?cid=100000578&pid=4

/*

*/

#include <cstdio>
#include <cstring>

int months[13][2] = { 
	{0,0}, {31,31}, {28,29}, {31,31}, {30,30}, {31,31}, 
	{30,30}, {31,31}, {31,31}, {30,30}, {31,31}, {30,30}, {31,31} };

bool isLeap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main() {
	int m;
	int year, month, day;
	int d;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			scanf("%d %d %d %d", &year, &month, &day, &d);
			while (d--) {
				day++;
				if (day == months[month][isLeap(year)]+1) { day = 1; month++; }
				if (month == 13) { year++; month = 1; }
			}
			printf("%04d-%02d-%02d\n", year, month, day);
		}
	}
	
	return 0;
}