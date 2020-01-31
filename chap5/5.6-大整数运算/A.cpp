// http://codeup.cn/problem.php?cid=100000593&pid=0

/*
两个加数不超过1000位，数组应开得更大一些
*/

#include <cstdio>
#include <cstring>

struct bign{
	int d[1010]; 
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]){
	bign a;
	a.len = strlen(str);
	for (int i=0; i<a.len; i++){
		if (str[a.len-i-1] >= '0' && str[a.len-i-1] <= '9')
			a.d[i] = str[a.len-i-1] - '0';
	}
	return a;
}

int compare(bign a, bign b){
	if (a.len>b.len) return 1;
	else if (a.len<b.len) return -1;
	else {
		for (int i=a.len-1; i>=0; i--){
			if (a.d[i]>b.d[i]) return 1;
			else if (a.d[i]<b.d[i]) return -1;
		}
		return 0;
	}
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

bign sub(bign a, bign b){
	bign c;
	for (int i=0; i<a.len || i<b.len; i++){
		if (a.d[i]<b.d[i]){
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len >= 2 && c.d[c.len-1]==0){
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
	char a[1000], b[1000];
	while (scanf("%s %s", a, b) != EOF){
		if (a[0] != '-' && b[0] != '-') {
			bign c = add(change(a), change(b));
			print(c);
		}
		else if (a[0] == '-' && b[0] == '-') {
			bign aa = change(a);
			aa.len--;
			bign bb = change(b);
			bb.len--;
			bign c = add(aa,bb);
			printf("-");
			print(c);
		}
		else if (a[0] == '-' && b[0] != '-') {
			bign aa = change(a);
			aa.len--;
			bign bb = change(b);
			bign c;
			if(compare(aa,bb)==1) {
				c = sub(aa,bb);
				printf("-");
			}
			else c = sub(bb,aa);
			print(c);
		}
		else {
			bign aa = change(a);
			bign bb = change(b);
			bb.len--;
			bign c;
			if(compare(aa,bb)==-1) {
				c = sub(bb,aa);
				printf("-");
			}
			else c = sub(aa,bb);
			print(c);
		}
		printf("\n");
	}
	return 0;
}