// http://codeup.cn/problem.php?cid=100000602&pid=1

/*

*/

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (n--){
			string a;
			stack<char> parenthesis;
			bool flag = false;
			cin >> a;
			for (int i=0; i<a.size(); i++){
				if (a[i]=='(' || a[i]=='[' || a[i]=='{') parenthesis.push(a[i]);
				else if (a[i] == ')') {
					if (!parenthesis.empty() && parenthesis.top() == '(') parenthesis.pop();
					else {
						printf("no\n");
						flag = true;
						break;
					}
				}
				else if (a[i] == ']') {
					if (!parenthesis.empty() && parenthesis.top() == '[') parenthesis.pop();
					else {
						printf("no\n");
						flag = true;
						break;
					}
				}
				else if (a[i] == '}') {
					if (!parenthesis.empty() && parenthesis.top() == '{') parenthesis.pop();
					else {
						printf("no\n");
						flag = true;
						break;
					}
				}
			}
			if (!flag){ // 未输入no
				if (parenthesis.empty()) printf("yes\n"); // 栈为空([])
				else printf("no\n"); // 栈非空 ([]
			} 
			
		}
	}



	return 0;
}