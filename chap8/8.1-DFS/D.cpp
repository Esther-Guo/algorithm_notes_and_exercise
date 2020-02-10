// http://codeup.cn/problem.php?cid=100000608&pid=3

/*

*/

#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int arr[11];
bool flag[11] = {false};
bool no_solute = true;

void generate(int index) {
	if (index == n+1) {
		bool valid = true;
		for (int i=1; i<=n; i++) {
			for (int j=i+1; j<=n; j++) {
				if (abs(i-j) == abs(arr[i]-arr[j])) {
					valid = false;
					return;
				}
			}
		}
		if (valid) {
			no_solute = false;
			for (int i=1; i<=n; i++) {
				i==1? printf("%d", arr[i]):printf(" %d", arr[i]);
			}
			printf("\n");
		}
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
		if (no_solute) printf("no solute!\n");
		no_solute = true; // 记得复原 
	}
	return 0;
}

