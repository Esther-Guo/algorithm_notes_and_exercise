// http://codeup.cn/problem.php?cid=100000584&pid=5

/*
添加溶液时计算浓度不是简单地除以二，还应考虑体积的关系。
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
		double ans_W = P[0];
		int ans_V = V;
		for (int i=1;i<n;i++){
			double temp = (ans_W * ans_V + P[i] * V) / (ans_V + V);
			if (temp <= W){
				ans_W  =  temp;
				ans_V += V;
			}
			else break;
		}
		ans_W = ans_W/100.0;
		printf("%d %.2f\n", ans_V, ans_W);
	}
	return 0;
}