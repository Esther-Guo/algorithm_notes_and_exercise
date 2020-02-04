// http://codeup.cn/problem.php?cid=100000604&pid=1

/*

*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// use string
int main() {
	string a;
	while(cin >> a){
		do {
			cout << a << endl;
		} while (next_permutation(a.begin(), a.end()));
	    printf("\n");
	}
	return 0;
}

// use char[]
int main() {
	char a[10];
	while(scanf("%s", a)!=EOF){
		do {
			printf("%s\n", a);
		} while (next_permutation(a, a+strlen(a)));
		printf("\n");
	}	
	return 0;
}