// http://codeup.cn/problem.php?cid=100000588&pid=5

/*

*/

#include <cstdio>
#include <cstring>

int main() {
	int a[2][3]={0}, b[3][2]={0};
	int num;
	while(scanf("%d", &num) != EOF){
		a[0][0] = num;
		for (int i=0;i<2;i++){
			for (int j=0;j<3;j++){
				if (i==0&&j==0) continue;
				else scanf("%d", &a[i][j]);
			}
		}
		for (int i=0;i<3;i++){
			for (int j=0;j<2;j++){
 				scanf("%d", &b[i][j]);
			}
		}
		// print
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++){
				printf("%d ", a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j]);
			}
			printf("\n");
		}
		
		memset(a, 0, sizeof(a)); // 记得初始化 
		memset(a, 0, sizeof(b));
	}
	return 0;
}