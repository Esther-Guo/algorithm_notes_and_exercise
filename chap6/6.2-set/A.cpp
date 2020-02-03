// http://codeup.cn/problem.php?cid=100000597&pid=0 

/*

*/

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<int> sets[51];
int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		for (int i=1; i<=n; i++) {
			int m;
			scanf("%d", &m);
			while (m--){
				int num;
				scanf("%d", &num);
				sets[i].insert(num);
			}
		}
		int k;
		scanf("%d", &k);
		while (k--){
			int set1, set2;
			scanf("%d %d", &set1, &set2);
			set<int>::iterator i1,i2;
			i1 = sets[set1].begin();
			i2 = sets[set2].begin();
			int cnt=0;
            // 采用双指针法遍历两个数组
			while(1){
				while (i1 != sets[set1].end() && *i1<*i2){
					i1++;
				}
				while (i2 != sets[set2].end() && *i2<*i1){
					i2++;
				}
				if (i1 == sets[set1].end() || i2 == sets[set2].end()) break;
				if (*i1 == *i2){
					cnt++;
					i1++;
					i2++;
				}
			} 
			int size1 = sets[set1].size();
			int size2 = sets[set2].size();
			
			double ans = (100.0*cnt)/(size1+size2-cnt);
			printf("%.1lf%%\n", ans); // 打印%需要输入%% 
		}
			
	}
	return 0;
}

// 下面记录OJ提示超时或内存超限的方法

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<int> sets[51];
int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		for (int i=1; i<=n; i++) {
			int m;
			scanf("%d", &m);
			while (m--){
				int num;
				scanf("%d", &num);
				sets[i].insert(num);
			}
		}
		int k;
		scanf("%d", &k);
		while (k--){
			int set1, set2;
			scanf("%d %d", &set1, &set2);
			int size1 = sets[set1].size();
			int size2 = sets[set2].size();
            // 遍历set2并插入set1
			for (set<int>::iterator it=sets[set2].begin(); it != sets[set2].end(); it++){
				sets[set1].insert(*it);
			}
			int nt = sets[set1].size(); // 两数组独立数字的合集
			int nc = size2-(nt-size1); // 两数字重合数字
			double ans = (100.0*nc)/nt;
			printf("%.1lf%%\n", ans);
		}
			
	}
	return 0;
}