// http://codeup.cn/problem.php?cid=100000596&pid=1

/*
vector容器中存放字符串，尽量避免使用char*，因为char*指向地址，容易造成不必要的麻烦。
如题中stuName如果使用char*存储，则每次读入都会改变之前已存储进容器的名字，最终所有stuName
都与最后一个名字一致。应使用string来避免该问题。
使用string时要用cin和cout读入和输出。
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 2510;

vector<string> course[MAX];
int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		string stuName;
		for (int i = 0; i < n; i++) {
			cin >> stuName;
			int classNum;
			scanf("%d", &classNum);
			while (classNum--) {
				int courseId;
				scanf("%d", &courseId);
				course[courseId].push_back(stuName);
			}
		}
		for (int i = 1; i <= k; i++) {
			sort(course[i].begin(), course[i].end());
			printf("%d %d\n", i, course[i].size());
			for (int j = 0; j < course[i].size(); j++) {
				cout << course[i][j] << endl;
			}
		}
	}
	return 0;
}