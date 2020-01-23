// 尚未通过
// http://codeup.cn/problem.php?cid=100000584&pid=5

/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int C, n, V, W;
	int P[110];
	scanf("%d", &C);
	while (C--) {
		scanf("%d %d %d", &n, &V, &W);
		
		for (int i=0;i<n;i++){
			scanf("%d", &P[i]);
		}
		sort(P, P+n);
		if (P[0] > W) {
			printf("0 0.00\n");
			continue;
		}
		double ans_W = P[0]/100.0;
		int ans_V = V;
		for (int i=1;i<n;i++){
			if ((ans_W+P[i])/2 <= W){
				ans_W  =  (ans_W+P[i]/100.0)/2;
				ans_V += V;
			}
			else break;
		}
		printf("%d %.2f\n", ans_V, ans_W);
	}
	return 0;
}