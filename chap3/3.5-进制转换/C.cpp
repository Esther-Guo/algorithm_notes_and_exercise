// http://codeup.cn/problem.php?cid=100000579&pid=2

/*
30位十进制数字太大，只能使用字符数组存储。
*/

#include <cstdio>
#include <cstring>

int main() {
	char c[35];
	int num[35];
	int bin[150] = { 0 };
	int index = 0, n = 0, k = 0;
	while (scanf("%s", c) != EOF) { //使用字符串一次性存储再单独拿出来处理
		for (int m = 0; m < strlen(c); m++) {
			num[index++] = c[m]-48;
		}
		do {
			bin[n++] = num[index-1] % 2; // index=n-1
			// 大数除以2取整
			int remain = 0;
			for (int j = k; j < index; j++) { // 遍历数组
				if (remain) { // 高位有余数
					remain = num[j] % 2;
					num[j] = (10 + num[j]) / 2;
				}
				else { // 高位已处理完毕
					remain = num[j] % 2;
					num[j] /= 2;
				}
				if (k == j && !num[j]) k++; // 高位除以2后取整为0
			}
		} while (k < index);
        // 倒序打印二进制数
		for (int i = n - 1; i >= 0; i--) {
			printf("%d", bin[i]);
		}
		printf("\n");
        // 初始化
		index = n = k = 0;
		memset(bin, 0, sizeof(bin));
	}
	return 0;
}