// http://codeup.cn/problem.php?cid=100000608&pid=1

/*

*/

#include <cstdio>

using namespace std;

int n, r;
int arr[21];
bool flag[21] = {false};

void generate(int index) {
	if (index == r+1) {
		for (int i=1; i<=r; i++) {
			i!=1? printf(" %d", arr[i]):printf("%d", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i=1; i<=n; i++) {
		if (flag[i] == false && i > arr[index-1]) {
			flag[i] = true;
			arr[index] = i;
			generate(index+1);
			flag[i] = false;
		}
	}
	
}

int main() {
	
	while (scanf("%d %d", &n, &r) != EOF) {
		generate(1); 
	}
	return 0;
}

