// http://codeup.cn/problem.php?cid=100000607&pid=1

/*
未使用链表……
*/

#include <cstdio>

using namespace std;

struct Node {
    int flag;
	int data;
}node[100010];

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i=0; i<100010; i++) {
			node[i].flag = 0;
		}
		int id, grade;
		for (int i=0; i<n+m; i++) {
			scanf("%d %d", &id, &grade);
			node[id].data = grade;
			node[id].flag = 1; 
		}
		for (int i=0; i<100010; i++) {
			if (node[i].flag) printf("%d %d\n", i, node[i].data);
		}
	}
    
    
    return 0;
}

