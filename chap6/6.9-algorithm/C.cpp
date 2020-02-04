// http://codeup.cn/problem.php?cid=100000604&pid=2

/*

*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	string a;
	while(getline(cin, a)){
		reverse(a.begin(), a.end());
		cout << a << endl;
	}	
	return 0;
}