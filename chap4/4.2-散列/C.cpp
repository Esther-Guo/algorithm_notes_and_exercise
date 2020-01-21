// http://codeup.cn/problem.php?cid=100000582&pid=2

/*

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int m;
	while (scanf("%d", &m) != EOF) {
		int num[100010] = {0};
		int hashTable[100010] = {0};
		for (int i = 0;i < m;i++){
			scanf("%d", &num[i]);
			hashTable[num[i]]++;
		}
		for (int i=0;i<m;i++){
			if (hashTable[num[i]] == 1) { // 有且仅有一次
				printf("%d\n", num[i]);
				break;
			}
			if (i == m-1) printf("None\n");
		}
	}
	return 0;
}