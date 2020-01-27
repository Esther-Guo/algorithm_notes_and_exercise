// 尚未通过 附参考 https://www.cnblogs.com/xbwer/p/3866486.html
// http://codeup.cn/problem.php?cid=100000584&pid=2

/*
double型输入要用%lf, 输出用%f.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct gas_station {
	double dist; // dist to Hangzhou 
	double unit_price; // price per unit
}gs[510];

bool cmp(gas_station a, gas_station b) { // sort by dist(near to far)
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
		gs[station_num].dist = total_dist; // put destination as the last station
		gs[station_num].unit_price = 100000;
		if (gs[0].dist != 0) { // if the first gas station is not at the beginning, the car cannot move at all
			printf("The maximum travel distance = 0.00\n");
			continue;
		}
		double currnt_len = 0;
		double max_dist = max_capacity * avg_dist; // the max dist between two stations
		bool end = 0; // flag denotes whether to start new while loop
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
		double price = 0, currnt_gas = 0;
		currnt_len = 0;
		for (int i = 0; i < station_num; i++) {
			if (i == station_num - 1) {
				price += ((total_dist - gs[i].dist) / avg_dist - currnt_gas)* gs[i].unit_price;
				break;
			}

			int next = i;
			for (int j = i + 1; j <= station_num; j++) {
				if (gs[j].unit_price <= gs[next].unit_price && gs[j].dist <= gs[i].dist + max_dist) {
					next = j;
					break;
				}
			}
			if (next == i) { // max_dist内没有更便宜的加油站，加满
				price += (max_capacity - currnt_gas) * gs[i].unit_price;
				double temp_price = 100000;
				for (int j = i + 1; j <= station_num; j++) {
					if (gs[j].dist <= gs[i].dist + max_dist && gs[j].unit_price < temp_price) {
						temp_price = gs[j].unit_price;
						next = j;
					}
				}
				currnt_gas = max_capacity - (gs[next].dist - gs[i].dist) / avg_dist;
			}
			else {
				price += ((gs[next].dist - gs[i].dist) / avg_dist - currnt_gas) * gs[i].unit_price;
				currnt_gas = 0;
			}
			currnt_len = gs[next].dist;
			i = next - 1;
		}
		printf("%.2f\n", price);

	}
	return 0;
}