// http://codeup.cn/problem.php?cid=100000593&pid=1

/*
数组要开的足够大！
*/

#include <cstdio>
#include <cstring>

struct bign{
	int d[4000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign multi(bign a, int b){
	bign c;
	int carry = 0;
	for (int i=0; i<a.len; i++){
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0){
		c.d[c.len++] = carry%10;
		carry /= 10;
	}
	return c;
} 

void print(bign a){
	for (int i=a.len-1; i>=0; i--){
		printf("%d", a.d[i]);
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF){
		if (n == 0) { printf("1\n"); continue;}
		bign ans;
		ans.len=1;
		ans.d[0]=1;
		for (int i=1; i<=n; i++){
			ans = multi(ans, i);
		}
		print(ans);
		printf("\n");
	}
	return 0;
}