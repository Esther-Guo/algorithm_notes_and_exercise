// http://codeup.cn/problem.php?cid=100000583&pid=3

/*

*/

#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int m, n, array[92][9] = {0}, p[9] = {0}, hash[9] = {false};
int count=0;

void queen(int index){
	if (index == 9) {
		bool flag = true;
		for (int i=1;i<=8;i++){
			for (int j=i+1;j<=8;j++){
				if (abs(i-j) == abs(p[i]-p[j])){
					flag = false;
				}
			}
		}
		if (flag) {
			for (int i=1;i<=8;i++){
				array[count][i] = p[i];
			}
			count++;
		}
        return;
	}
	for (int i=1;i<=8;i++){
		if (hash[i] == false){
			p[index] = i;
			hash[i] = true;
			queen(index+1);
			hash[i] = false;  
		}
	}
}

int main() {
	scanf("%d", &m);
	queen(1);
	while (m--){
		scanf("%d", &n);
		for (int i=1;i<=8;i++) printf("%d", array[n-1][i]);
		printf("\n");
	}
	return 0;
}