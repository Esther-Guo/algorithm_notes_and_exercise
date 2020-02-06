// http://codeup.cn/problem.php?cid=100000606&pid=0

/*
same as 6.5-A 用queue并不方便，因此使用数组
如果利用下标执行交换，查找最值一定分两步进行。因为也许最小值和第一个数（恰好是最大值）
交换之后，此时最大值的下标已经变了。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10]={0};

void input() {
    for (int i=1; i<10; i++){
    	scanf("%d", &a[i]);
    }
}

void edit() {
	int max = 0;
	int min = 0;
    // 分两次进行
	for (int i=1; i<10; i++) {
		if (a[i]<a[min]) min = i;
	}
	swap(a[min], a[0]);
	for (int i=1; i<10; i++) {
		if (a[i]>a[max]) max = i;
	}
	swap(a[max], a[9]);
}

void output() {
	for (int i=0; i<10; i++){
    	printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
	int num;
	while (scanf("%d", &num) != EOF){
		a[0] = num;
		input();
    	edit();
    	output();
	}
	
    return 0;
}