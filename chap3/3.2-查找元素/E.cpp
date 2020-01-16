// http://codeup.cn/problem.php?cid=100000576&pid=4

/*

*/

#include <cstdio>
#include <cstring>
#include <cmath>

struct Stu {
	int id;
	char name[200];
	char gender[50];
	int age;
} students[20];

int main() {
	int n, m;
	int lookup;
	scanf("%d", &m); // 样例数
	while (m--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %s %s %d", &students[i].id, students[i].name, students[i].gender, &students[i].age);
		}
		scanf("%d", &lookup);
		for (int j = 0; j < n; j++) {
			if (students[j].id == lookup) {
				printf("%d %s %s %d\n", students[j].id, students[j].name, students[j].gender, students[j].age);
			}
		}
	}
	return 0;
}