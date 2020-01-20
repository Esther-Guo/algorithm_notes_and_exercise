// http://codeup.cn/problem.php?cid=100000581&pid=2

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct student {
	char id[10];
	char name[10];
	int grade;
}stu[100010];

bool cmp1(student a, student b) {
	return strcmp(a.id, b.id) < 0;
}

bool cmp2(student a, student b) {
	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else return strcmp(a.id, b.id) < 0;
}

bool cmp3(student a, student b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	else return strcmp(a.id, b.id) < 0;
}
int main() {
	int n,c;
	int case_num = 1;
	while (scanf("%d %d", &n, &c) != EOF) {
		if (n) {
			for (int i = 0; i < n; i++) {
				scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
			}
			switch (c) {
			case 1: sort(stu, stu + n, cmp1); break;
			case 2: sort(stu, stu + n, cmp2); break;
			case 3: sort(stu, stu + n, cmp3); break;
			}
			printf("Case %d:\n", case_num);
			for (int i = 0; i < n; i++) {
				printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
			}
			case_num++;
		}
		else break;
	}
	return 0;
}