// http://codeup.cn/problem.php?cid=100000588&pid=4

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	int a[11]={0};
	int num;
	while(scanf("%d", &num) != EOF){
		a[num]++;
		for (int i=0;i<19;i++){
			scanf("%d", &num);
			a[num]++;
		}
		int mode=0, temp=0;
		for (int i=10;i>0;i--){
			if (a[i] >= temp) {
				temp = a[i];
				mode = i;
			}
		}
		printf("%d\n", mode);
		memset(a, 0, sizeof(a)); // 记得初始化 
	}
	return 0;
}