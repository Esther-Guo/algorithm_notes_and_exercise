// http://codeup.cn/problem.php?cid=100000620&pid=1

/*
邻接矩阵实现
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;

int adj[maxn][maxn] = { 0 };
bool flag[maxn] = { false }; // if the node has been traversed
int n, m; // vertices, edges

void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (!flag[i] && adj[x][i] == 1) {
			flag[i] = true;
			dfs(i);
		}
	}
}

int main()
{
	int a, b;
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0) break;
		while (m--) {
			scanf("%d %d", &a, &b);
			adj[a][b] = 1;
			adj[b][a] = 1;
		}
		if (!flag[a]) {
			flag[a] = true;
			dfs(a);
		}
		int i;
		for (i = 1; i <= n; i++) {
			if (flag[i] == false) {
				printf("NO\n");
				break;
			}
		}
		if (i == n+1) printf("YES\n");
		memset(flag, 0, sizeof(flag));
		memset(adj, 0, sizeof(adj));
	}
	
	return 0;
}
