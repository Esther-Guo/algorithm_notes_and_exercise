// http://codeup.cn/problem.php?cid=100000581&pid=8

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct student {
	char id[25];
	int m;
	int grade;
}stu[1010];

bool cmp(student a, student b) {
	if (a.grade != b.grade) return a.grade > b.grade;
	else return strcmp(a.id, b.id) < 0;
}

int main() {
	int N, M, G;
	int scores[10];
	int num;
	while (scanf("%d", &N) != EOF) {
		if (N) {
			int count = 0;
			scanf("%d %d", &M, &G);
			for (int i = 0; i < M; i++) {
				scanf("%d", &scores[i]);
			}
			for (int i = 0; i < N; i++) {
				scanf("%s %d", stu[i].id, &stu[i].m);
				stu[i].grade = 0;
				for (int j = 0; j < stu[i].m; j++) {
					scanf("%d", &num);
					stu[i].grade += scores[num - 1];
				}
				if (stu[i].grade >= G) count++;
			}
			printf("%d\n", count);
			sort(stu, stu + N, cmp);
			for (int i = 0; i < count; i++) {
				printf("%s %d\n", stu[i].id, stu[i].grade);
			}
		}
		else break;
	}
	return 0;
}