// 尚未通过
// http://codeup.cn/problem.php?cid=100000584&pid=3

/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	return a>b;
}

int main() {
	int L, N;
	int blocks[610] = {0};
	while (scanf("%d %d", &L, &N) != EOF) {
		for (int i=0;i<N;i++){
			scanf("%d", &blocks[i]);	
		}
		sort(blocks, blocks+N, cmp);
		int count = 0;
		
		for (int i=0;i<N;i++){
			if (L <= blocks[i]) {
				L = 0;
				count++;
				break;
			}
			else {
				L -= blocks[i];
				count++;
			}	
		}
		if (L) {
			printf("impossible\n");
			break;		
		}
		else {
			printf("%d\n", count);
		}
	}
	return 0;
}