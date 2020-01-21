// http://codeup.cn/problem.php?cid=100000582&pid=0

/*
每组测试数据后记得还原哈希表
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int friends[210][2] = { 0 };
	while (scanf("%d %d", &N, &M) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &friends[i][0]);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (friends[i][0] == friends[j][0]) friends[i][1]++;
			}
		}
		for (int i = 0; i < N; i++) {
			if (friends[i][1] > 1) printf("%d\n", friends[i][1] - 1); // 遍历时多加了自己，要减去
			else printf("BeiJu\n");
		}
		memset(friends, 0, sizeof(friends));
	}
	return 0;
}