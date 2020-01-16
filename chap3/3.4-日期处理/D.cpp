// http://codeup.cn/problem.php?cid=100000578&pid=3

/*

*/

#include <cstdio>
#include <cstring>

int months[13] = { 0, 31, 28, 31, 30, 31, 30 ,31, 31 ,30, 31, 30, 31 };

int main() {
	int n;
	int year, month, day;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d %d %d", &year, &month, &day);
			day++;
			if (day == months[month] + 1) { month++; day = 1; }
			if (month == 13) { year++; month = 1; }
			printf("%04d-%02d-%02d\n", year, month, day);
		}
	}
	
	return 0;
}