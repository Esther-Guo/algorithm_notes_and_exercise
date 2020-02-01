// http://codeup.cn/problem.php?cid=100000593&pid=2

/*
有许多需要考虑的边界条件，尤其是对于小数部分的处理。
*/

#include <cstdio>
#include <cstring>

struct bign{
	int d[110];
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

void print(bign a){
	for (int i=a.len-1; i>=0; i--){
		printf("%d", a.d[i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--){
		char s1[110], s2[110];
		scanf("%s %s", s1, s2);
		bign a, b, af, bf; // a为整数部分，af为小数部分 
		// 以.为分隔符将string转bign 
		bool flag = 0;
		for (int i=strlen(s1)-1; i>=0; i--){
			if (s1[i]=='.') flag = 1;
			else if (flag) a.d[a.len++] = s1[i]-'0';
			else af.d[af.len++] = s1[i]-'0';
		}
		flag = 0;
		for (int i=strlen(s2)-1; i>=0; i--){
			if (s2[i]=='.') flag = 1;
			else if (flag) b.d[b.len++] = s2[i]-'0';
			else bf.d[bf.len++] = s2[i]-'0';
		}
		 
		bign ans, ansf;
		bign carry;
		// 小数部分的处理，为保证一一对应可以低位补零 
		if (af.len>bf.len) {
			for (int i=bf.len-1; i>=0; i--){ // 从高位开始倒序处理 
				bf.d[i+af.len-bf.len] = bf.d[i];
			}
			for (int i=0; i<af.len-bf.len; i++){
				bf.d[i] = 0;
			} 
			bf.len = af.len;
		}
		else if (af.len<bf.len){
			for (int i=af.len-1; i>=0; i--){
				af.d[i+bf.len-af.len] = af.d[i];
			}
			for (int i=0; i<bf.len-af.len; i++){
				af.d[i] = 0;
			} 
			af.len = bf.len;
		}
		ansf = add(af, bf);
		// 有进位则记录进位，且小数部分不打印进位 
		if (ansf.len>af.len) { carry.d[0] = 1; carry.len++; ansf.len--;}
		// 处理小数部分末尾的0 
		int zeroes = 0; // 末尾0的个数 
		for (int i=0;i<ansf.len;i++){
			if (ansf.d[i]==0) zeroes++;
			else break;
		}
		for (int i=zeroes;i<ansf.len;i++){
			ansf.d[i-zeroes] = ansf.d[i];
		}
		ansf.len -= zeroes;
		// 整数部分相加 
		ans = add(a, b);
		if (carry.len) ans = add(ans, carry); 
		print(ans);
		printf(".");
		print(ansf);
		printf("\n");
	}
	return 0;
}