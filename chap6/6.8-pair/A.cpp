// http://codeup.cn/problem.php?cid=100000563&pid=0

/*
数学知识不牢固！重心坐标是三点坐标的平均值。重心将每条中线的三等分点。
*/

#include <cstdio>
#include <iostream> 
#include <utility>

using namespace std;

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		if (n) {
			while (n--){
				pair<double, double> a, b, c;
				scanf("%lf %lf %lf %lf %lf %lf", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second);
				pair<double, double> point; // 重心坐标x,y
				point.first = (a.first+b.first+c.first)/3;
				point.second = (a.second+b.second+c.second)/3;
				printf("%.1lf %.1lf\n", point.first, point.second);
			}
			
		}
		else break;
	}
	
	
	
	return 0;
}