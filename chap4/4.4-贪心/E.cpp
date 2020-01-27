// http://codeup.cn/problem.php?cid=100000584&pid=4

/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct room{
	double java_bean;
	double cat_food;
	double unit_price;
}r[1010];

bool cmp(room a, room b){
	return a.unit_price>b.unit_price;
}

int main() {
	int M, N;
	while (scanf("%d %d", &M, &N) != EOF) {
		if (M == -1 && N == -1) break;
		else{
			for (int i=0;i<N;i++){
				scanf("%lf %lf", &r[i].java_bean, &r[i].cat_food);
				r[i].unit_price = r[i].java_bean / r[i].cat_food;
			}
			sort(r, r+N, cmp);
			double amount = 0;
			for (int i=0;i<N;i++){
				if (M>=r[i].cat_food){
					M -= r[i].cat_food;
					amount += r[i].java_bean;
				}
				else {
					amount += r[i].unit_price * M;
					break;
				}
			}
			printf("%.3lf\n", amount);
		}
	}
	return 0;
}