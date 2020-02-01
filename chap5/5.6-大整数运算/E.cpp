// http://codeup.cn/problem.php?cid=100000593&pid=4

/*
codeup一直提示运行错误，牛客就全部通过了:( 看不出哪有问题，好暴躁！！
*/

#include <cstdio>
#include <cstring>
#include <cmath>

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {
	bign a;
	for (int i=strlen(str)-1; i>=0; i--) {
		a.d[a.len++] = str[i]-'0';
	}
	return a;
}

int compare(bign a, bign b) {
	if (a.len > b.len) return 1;
	else if (a.len < b.len) return -1;
	else {
		for (int i = a.len - 1; i >= 0; i--) {
			if (a.d[i] > b.d[i]) return 1;
			else if (a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
}
 
int main(){
    bign nums[110];
	int n;
    while(scanf("%d",&n)!=EOF){
        char s[110];
        for (int i=0; i<n; i++){
        	scanf("%s", s);
        	nums[i] = change(s);
        }
        for (int i=0; i<n-1; i++){
        	 int index = i;
        	 for (int j = i+1; j<n; j++){
        	 	if (compare(nums[index],nums[j])==1) { // nums[index] > nums[j] 
        	 		index = j;
        	 	}
        	 }
        	 if (index != i){
        	 	bign temp = nums[i];
        	 	nums[i] = nums[index];
				nums[index] = temp;	
        	 }
        }
        for (int i=0; i<n; i++){
        	print(nums[i]);
        	printf("\n");
        }
    }
    return 0;
}