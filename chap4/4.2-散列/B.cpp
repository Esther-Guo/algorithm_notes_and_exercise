// http://codeup.cn/problem.php?cid=100000582&pid=1

/*
本题使用哈希表去重。在不能定义动态数组的前提下，数组开得太大容易导致栈溢出。
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	while (m--) {
		int n;
		scanf("%d", &n);
		int hash_table_1[1010] = { 0 };
		int nums[110] = { 0 }, k1 = 0; // 第一行数字
		int uniq_nums[110] = { 0 }; // 第一行数字去重
		int max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
			if (!hash_table_1[nums[i]]) {
				hash_table_1[nums[i]]++;
				uniq_nums[k1++] = nums[i];
			}
			if (nums[i] > max) max = nums[i];
		}
		sort(uniq_nums, uniq_nums + k1); // 数字升序

		int hash_table_2[110] = { 0 };
		int group[110][1010] = { 0 }; // 最终存储结果的二维数组 
		int group_nums[110] = { 0 }, k2 = 0; // 存储第二行数据
		int uniq_group_nums[110] = { 0 }; // 第二行组数去重
		for (int i = 0; i < n; i++) {
			scanf("%d", &group_nums[i]);
			if (!hash_table_2[group_nums[i]]) {
				hash_table_2[group_nums[i]]++;
				uniq_group_nums[k2++] = group_nums[i];
			}
			group[group_nums[i]][nums[i]]++;
		}
		sort(uniq_group_nums, uniq_group_nums + k2); // 组号升序

        // 打印结果
		for (int i = 0; i < k2; i++) {
			printf("%d={", uniq_group_nums[i]);
			for (int j = 0; j < k1; j++) {
				printf("%d=%d", uniq_nums[j], group[uniq_group_nums[i]][uniq_nums[j]]);
				if (j != k1 - 1) printf(",");
			}
			printf("}\n");
		}
	}
	return 0;
}