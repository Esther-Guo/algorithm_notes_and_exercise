// http://codeup.cn/problem.php?cid=100000602&pid=0

/*
codeup样例未全部通过，牛客通过，不知道哪里有问题！
本代码采取先处理乘除后处理加减的方法。注意加减处理时将栈中元素放入vector更方便使用。（或是处理加减时遇到减号则入栈相反数）
后附使用后缀表达式求值的代码。
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

// 后缀表达式
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node {
    double num; // 操作数
    char op; // 操作符
    bool flag; // true为操作数, false为操作符
};

string str;
stack<node> s; // 操作符栈
queue<node> q; // 后缀表达式序列
map<char, int> op;

void Change() { // 中缀表达式转后缀表达式
    double num;
    node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true; // 标记为操作数
            temp.num = str[i++] - '0'; // 记录操作数第一位
            // 获取完整操作数
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp); // 操作数加入后缀表达式队列
        }
        else {
            temp.flag = false; // 标记为操作符
            // 如果操作符栈栈顶元素的优先级高于当前操作符
            // 则将栈内操作符依次弹出直到栈顶元素优先级低于或等于当前操作符
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp); // 以上弹出操作结束后将当前操作符压入栈
            i++;
        }
    }
    // 字符串遍历结束后，如果栈中还有操作符，则依次放入后缀表达式
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

double Cal() { // 计算后缀表达式
    double temp1, temp2;
    node cur, temp;
    while (!q.empty()) { // 只要后缀表达式非空
        cur = q.front(); // cur记录队首元素
        q.pop();
        if (cur.flag == true) s.push(cur); // 若为操作数则压入栈
        else { // 操作符
            temp2 = s.top().num; // 第二操作数
            s.pop();
            temp1 = s.top().num; // 第一操作数
            s.pop();
            temp.flag = true; // 临时记录操作数
            if (cur.op == '+') temp.num = temp1 + temp2;
            else if (cur.op == '-') temp.num = temp1 - temp2;
            else if (cur.op == '*') temp.num = temp1 * temp2;
            else temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num; // 栈顶元素即为最终结果 
}

int main() {
    // 设置运算符优先级
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0") { // 逗号表达式，返回最后一个表达式的bool值
        // 去掉表达式中的空格
        for (string::iterator it = str.begin(); it != str.end(); it++) {
            if (*it == ' ') str.erase(it);
        }
        while (!s.empty()) s.pop(); // 清空栈 
        Change();
        printf("%.2lf\n", Cal());
    }
    return 0;
}