// http://codeup.cn/problem.php?cid=100000608&pid=0

/*

*/

#include <cstdio>

using namespace std;

int n;
int arr[11];
bool flag[11] = {false};

void generate(int index) {
	if (index == n+1) {
		for (int i=1; i<=n; i++) {
			i!=1? printf(" %d", arr[i]):printf("%d", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i=1; i<=n; i++) {
		if (flag[i] == false) {
			flag[i] = true;
			arr[index] = i;
			generate(index+1);
			flag[i] = false;
		}
	}
	
}

int main() {
	
	while (scanf("%d", &n) != EOF) {
		generate(1); 
	}
	return 0;
}

