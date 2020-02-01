// http://codeup.cn/problem.php?cid=100000593&pid=5

/*
测试用例为多组。
*/

#include <cstdio>
#include <cstring>
#include <cmath>

struct bign{
	int d[4000];
	int len;
	bign(){
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
	char s[1010];
	while(scanf("%s", s) != EOF){
		bign num = change(s);
		bign binary;
		do {
			int r = 0; // 记录余数,循环内清零 
			num = divide(num, 2, r); 
			binary.d[binary.len++] = r;
		} while (!(num.len==1 && num.d[0]==0));
		
		// 处理倒序后作为开头的0 
		int zeroes = 0; // 0的个数 
		for (int i=0;i<binary.len;i++){
			if (binary.d[i]==0) zeroes++;
			else break;
		}
		for (int i=zeroes;i<binary.len;i++){
			binary.d[i-zeroes] = binary.d[i];
		}
		binary.len -= zeroes;
		
		bign sum, plus; // 存储十进制大数，乘数因子
		plus.d[0] = 1;
		plus.len = 1; 
		for (int i=binary.len-1; i>=0; i--){
			int num = binary.d[i];
			sum = add(sum, multi(plus, num));
			plus = multi(plus, 2);
		}
		print(sum);
		printf("\n");
	}
	
	
	
	return 0;
}