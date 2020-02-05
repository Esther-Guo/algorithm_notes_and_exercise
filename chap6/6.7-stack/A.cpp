// http://codeup.cn/problem.php?cid=100000602&pid=0

/*
codeup样例未全部通过，不知道哪里有问题！
本代码采取先处理乘除后处理加减的方法。注意加减处理时将栈中元素放入vector更方便使用。（或是处理加减时遇到减号则入栈相反数）
有时间再复习一下后缀表达式求值。
*/

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	string a;
	stack<double> nums;
	while (getline(cin, a)) {
		if (a[0] != '0') {
			int num = 0;
			bool before = false; // 符号前的空格 
			bool multi = false;
			bool divide = false;
			for (int i = 0; i < a.length(); i++) {
				if (a[i] >= '0' && a[i] <= '9') num = (num * 10 + (a[i] - '0')); // 计算整数的值
				if ((a[i] == ' ' && before == false) || i == a.length() - 1) { // 如遇到符号前的空格 或 最后一个数
					if (!multi && !divide) nums.push(num); // 前一个符号不是乘除，数字入栈
					else if (multi) { // 前一个符号是*，计算与前一个数的乘积并入栈
						double m = nums.top() * num; 
						nums.pop();
						nums.push(m);
						multi = false;
					}
					else if (divide) { // 前一个符号是/，计算与前一个数的商并入栈
						double n = nums.top() / num;
						nums.pop();
						nums.push(n);
						divide = false;
					}
					before = true; // 标记已经遍历符号的前一个空格
				}
				else if (a[i] == ' ' && before == true) { // 符号的后一个空格
					before = false; // 重新标记
					num = 0; // 数字清零
				}
				else { // 符号
					if (a[i] == '+') { // 标记为-1入栈，留之后处理
						nums.push(-1.0);
					}
					else if (a[i] == '-') { // 标记为-1入栈，留之后处理
						nums.push(-2.0);
					}
					else if (a[i] == '*') {
						multi = true;
					}
					else if (a[i] == '/') {
						divide = true;
					}
				}
			}
			// 至此，乘除法均已完成
			vector<double> arr;
			while (!nums.empty()) { // 将栈中的数倒序存入vector
				double n1 = nums.top();
				arr.push_back(n1);
				nums.pop();
			}
			double ans = 0; // 倒序计算加减法
			for (int i = arr.size()-1; i >= 0; i--) {
				if (i==arr.size()-1) ans += arr[i];
				else if (arr[i] == -1.0) {
					ans += arr[--i]; // 与前一个数相加
				}
				else if (arr[i] == -2.0) {
					ans -= arr[--i]; // 与前一个数相减
				}
			}
			printf("%.2lf\n", ans);

		}
		else break;
		
	}



	return 0;
}