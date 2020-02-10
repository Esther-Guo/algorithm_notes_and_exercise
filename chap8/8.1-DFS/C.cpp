// http://codeup.cn/problem.php?cid=100000608&pid=2

/*
一个小技巧，为了防止选择的序列重复（2,3,7/7,3,2），保存选择元素的
下标并保证下标为升序。
*/

#include <cstdio>
#include <cmath>

using namespace std;

int n, k;
int arr[21];
int chosen[21]; // 下标序列
int sum = 0;
int cnt = 0;
bool flag[21] = {false};

bool isPrime(int n) {
	if (n<=1) return false;
	for (int i=2; i<=(int)sqrt(n*1.0); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

void generate(int index, int sum) {
	if (index == k+1) {
		if (isPrime(sum)) cnt++;
		return;
	}
	for (int i=1; i<=n; i++) {
		if (flag[i] == false && i>=chosen[index-1]) {
			flag[i] = true;
			chosen[index] = i;
			generate(index+1, sum+arr[i]);
			flag[i] = false;
		}
	}
	
}

int main() {
	
	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i=1; i<=n; i++) {
			scanf("%d", &arr[i]);
		}
		generate(1,sum);
		printf("%d\n", cnt);
	}
	return 0;
}

