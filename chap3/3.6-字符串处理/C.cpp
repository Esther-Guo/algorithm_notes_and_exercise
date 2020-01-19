// http://codeup.cn/problem.php?cid=100000580&pid=2

/*
数组空间放开了给！心疼自己的时间！！
本题需要注意的细节较多。比如待处理字符串不可以直接整体转小写，避免本应大写的未匹配字符也被小写输出。
*/

#include <cstdio>
#include <cstring>

// 待匹配子串
void lower(char* s, int n) {
	while (n--) {
		if (s[n] >= 65 && s[n] <= 90) s[n] += 32;
	}
}

void process(char* s, char* string, char* ans) {
	int s_len = strlen(s);
	int str_len = strlen(string);
	int k = 0, j;
	for (int i = 0; i < str_len; i++) {
		ans[k] = string[i];
		if (string[i] >= 'A' && string[i] <= 'Z') string[i] += 32;
		if (string[i] == s[s_len - 1] && i >= s_len-1) { // 当前字母与s末位字母相同且已读入长度大于等于待比较子串长度
			for (j = 1; j < s_len; j++) { // 逐位倒序比较
				if (string[i - j] == s[s_len - 1 - j]) continue;
				else {
					k++;
					break;
				}
			}
			if (j == s_len) k -= (s_len-1); // 完全匹配，将k值向前置
		}
		else k++;
	}
	ans[k] = '\0'; // 结尾加入结束符
}


int main() {
	char s[1000];
	scanf("%s", s);
	lower(s, strlen(s));
	char strings[1000][1000];
	char ans[1000][1000];
	int n = 0;
	getchar(); // 吸收回车
	while (gets_s(strings[n++]) != NULL) {
		process(s, strings[n - 1], ans[n-1]);
	}
	// print all the strings without ' '
	int j = 0;
	while (--n) {
		for (int i = 0; i < strlen(ans[j]); i++) {
			if (ans[j][i] == ' ') continue;
			else printf("%c", ans[j][i]);
		}
		printf("\n");
		j++;
	}
	return 0;
}