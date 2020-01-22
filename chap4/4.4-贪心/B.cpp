// http://codeup.cn/problem.php?cid=100000584&pid=1

/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n) {
			double price = 0;
			while (n) {
				if (n <= 4) { price += 10; break; }
				else if (n <= 8) {
					price += (10 + 2 * (n - 4)); break;
				}
				else if (n <= 13) {
					price += (18 + 2.4 * (n - 8)); break;
				}
				else {
					n -= 8;
					price += 18;
				}
			}
			if ((int)(price / 0.1) % 10) printf("%.1f\n", price);
			else printf("%.0f\n", price);
		}
		else break;
	}
	return 0;
}