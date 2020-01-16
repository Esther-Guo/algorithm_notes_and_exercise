// http://codeup.cn/problem.php?cid=100000576&pid=2

/*
空间尽可能开大
*/

#include <cstdio>
#include <cstring>
#include <cmath>

struct Student {
	char id[100];
	char name[300];
	char gender[20]; 
	int age;
} stu[1001];

int main() {
	int n;
	int m;
	char num[10];
	int j;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s %s %s %d", stu[i].id, stu[i].name, stu[i].gender, &stu[i].age);
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%s", num);
			for (j = 0; j < n; j++) {
				if (!strcmp(stu[j].id, num)) {
					printf("%s %s %s %d\n", stu[j].id, stu[j].name, stu[j].gender, stu[j].age);
					break; // 注意及时中断，保证j不再递增
				}
			}
			if (j == n) printf("No Answer!\n");
		}
	}
	return 0;
}