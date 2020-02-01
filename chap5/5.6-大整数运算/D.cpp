// http://codeup.cn/problem.php?cid=100000593&pid=3

/*
一直说我输出超限，不知道哪里有问题！
*/

#include <cstdio>
#include <cstring>
#include <cmath>

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for (int i=0; i<a.len || i<b.len; i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp%10;
		carry = temp/10;
	}
	if (carry != 0) c.d[c.len++] = carry;
	return c;
}

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

bign divide(bign a, int b, int& r){ // r为余数
    bign c;
    c.len = a.len; // 商和被除数按位对应
    for (int i=a.len-1; i>=0; i--){ // 从高位开始
        r = r*10 + a.d[i];
        if (r<b) c.d[i] = 0; // 不够除
        else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while (c.len >= 2 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}

void print(bign a){
	for (int i=a.len-1; i>=0; i--){
		printf("%d", a.d[i]);
	}
}

int main() {
	int M, N; // M -> N
	while (scanf("%d %d", &M, &N)){
		char s[1000]; // x
		scanf("%s", s);
		bign sum, plus; // 存储十进制大数，乘数因子
		plus.d[0] = 1;
		plus.len = 1; 
		for (int i=0; i<strlen(s); i++){
			int num;
			if (s[strlen(s)-i-1] >= '0' && s[strlen(s)-i-1] <= '9') {
				num = s[strlen(s)-i-1] - '0';
			}
			else if (s[strlen(s)-i-1] >= 'A' && s[strlen(s)-i-1] <= 'Z') {
				num = s[strlen(s)-i-1] - 'A' + 10; // A -> 10
			}
			sum = add(sum, multi(plus, num));
			plus = multi(plus, M);
		}
		// 存储N进制数据
		char ans[1000];
		int len = 0; // 记录ans长度 
		 
		do {
			int r = 0; // 记录余数,循环内清零 
			sum = divide(sum, N, r); 
			if (r < 10) {
				ans[len++] = r+'0';
			}
			else {
				ans[len++] = r-10+'a';
			}
		} while (!(sum.len==1 && sum.d[0]==0));
		for (int i=0; i<len; i++){
			printf("%c", ans[len-i-1]);
		}
		printf("\n");
	}
	return 0;
}