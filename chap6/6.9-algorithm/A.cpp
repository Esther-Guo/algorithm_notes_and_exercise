// http://codeup.cn/problem.php?cid=100000604&pid=0

/*

*/

#include <cstdio>
#include <iostream> 
#include <algorithm>

using namespace std;

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		int temp, min_num, max_num;
		bool first = true;
		while (n--){
			scanf("%d", &temp);
			if (first) {
				min_num = max_num = temp;
				first = false;
			}
			else{
				min_num = min(min_num, temp);
				max_num = max(max_num, temp);
			}
		}
		printf("%d %d\n", max_num, min_num);
	}
	return 0;
}