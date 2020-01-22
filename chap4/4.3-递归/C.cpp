// http://codeup.cn/problem.php?cid=100000583&pid=2

/*
使用递归一般需要将变量声明为全局(main之外). 
bag(sum, index) = bad(sum, index+1) + bag(sum-array[index], index+1)
将原问题分解为：1.不包含当前物品(array[i-1])，由剩余物品构成sum 2.包含当前物品，由剩余物品构成sum-array[index-1] 
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 20;

int m, array[maxn] = {0};
int count;

int bag(int sum, int index){
	if (sum==0) return 1;
	else if (sum < 0||index>m) return 0; // 超出sum或是件数超限
	else return bag(sum, index+1) + bag(sum-array[index-1], index+1);
}

int main() {
	while (scanf("%d", &m) != EOF){
		for (int i=0;i<m;i++){
			scanf("%d", &array[i]);
		}
		count = bag(40, 1);
		printf("%d\n", count);
		memset(array, 0, sizeof(array));
	}
	return 0;
}