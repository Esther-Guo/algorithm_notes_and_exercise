// 尚未通过
// http://codeup.cn/problem.php?cid=100000584&pid=2

/*
double型输入要用%lf, 输出用%f.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct gas_station {
	double dist;
	double unit_price;
}gs[510];

bool cmp(gas_station a, gas_station b) {
	return a.dist < b.dist;
}

int main() {
	double max_capacity, total_dist, avg_dist;
	int station_num;
	while (scanf("%lf %lf %lf %d", &max_capacity, &total_dist, &avg_dist, &station_num) != EOF) {
		for (int i = 0; i < station_num; i++) {
			scanf("%lf %lf", &gs[i].unit_price, &gs[i].dist);
		}
		sort(gs, gs + station_num, cmp);
		gs[station_num].dist = total_dist;
		gs[station_num].unit_price = 100000;
		if (gs[0].dist != 0) {
			printf("The maximum travel distance = 0.00\n");
			continue;
		}
		double currnt_len = 0;
		double max_dist = max_capacity * avg_dist;
		bool end = 0;
		for (int i = 0; i < station_num; i++) {
			double dist_between = gs[i + 1].dist - gs[i].dist;
			if (dist_between > max_dist) {
				currnt_len += max_dist;
				printf("The maximum travel distance = %.2f\n", currnt_len);
				end = 1;
				break;
			}
			else {
				currnt_len = gs[i + 1].dist;
			}
		}
		if (end) continue;
		double price = 0;
		currnt_len = 0;
		for (int i = 0; i < station_num; i++) {
			currnt_len = gs[i].dist;
			int next = i;
			for (int j = i + 1; j <= station_num; j++) {
				if (gs[j].unit_price <= gs[next].unit_price && gs[j].dist <= gs[i].dist + max_dist) {
					next = j;
					break;
				}
			}
			if (next == i) {
				for (int j = i + 1; j <= station_num; j++) {
					if (gs[j].dist <= gs[i].dist + max_dist) next = j;
				}
			}
			price += (gs[next].dist - gs[i].dist) / avg_dist * gs[i].unit_price;
			i = next - 1;
		}
		printf("%.2f\n", price);

	}
	return 0;
}