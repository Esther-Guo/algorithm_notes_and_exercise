// http://codeup.cn/problem.php?cid=100000585&pid=1

/*
注意题目叙述，包括多个案例
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (n--){
			int k;
			int nums[90] = {0};
			scanf("%d", &k);
			for (int i = 0; i < k; i++) {
				scanf("%d", &nums[i]); 
			}
			bool flag = 0;
			if (nums[0] != nums[1]) {printf("0"); flag = 1;}
			for (int i = 1; i < k-1; i++){
				if ((nums[i]>nums[i-1] && nums[i]>nums[i+1]) || (nums[i]<nums[i-1] && nums[i]<nums[i+1]))
					if (flag) printf(" %d", i);
					else {printf("%d", i); flag = 1;}
			}
			if (nums[k-1] != nums[k-2]){
			    if (flag) printf(" %d", k-1);
			    else {printf("%d", k-1); flag = 1;}
			} 
			if (flag) printf("\n");
		}
		
	}
	return 0;
}