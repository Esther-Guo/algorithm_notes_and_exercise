// http://codeup.cn/problem.php?cid=100000605&pid=0

/*
same as 6.7-A
本代码采取后缀表达式的方法，同时结合队列使用。
*/

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
    // 如果栈中还有操作符，则依次放入后缀表达式
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