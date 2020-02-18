// http://codeup.cn/problem.php?cid=100000620&pid=0

/*
邻接表实现
*/

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 500010;

vector<int> adj[maxn];
bool flag[maxn] = { false }; // if the node exists
bool ano_flag[maxn] = { false }; // if the node has been traversed
int n;

void dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++) {
		if (!ano_flag[adj[x][i]]) {
			ano_flag[adj[x][i]] = true;
			dfs(adj[x][i]);
		}
	}
}

int main()
{
	int a, b, max = -1;
	while (scanf("%d", &a) != EOF) {
		scanf("%d", &b);
		if (a != b) {
			adj[a].push_back(b);
			adj[b].push_back(a);
			if (!flag[a]) {
				n++;
				flag[a] = true;
			}
			if (!flag[b]) {
				n++;
				flag[b] = true;
			}
		}
		else {
			if (!flag[a]) {
				n++;
				flag[a] = true;
			}
		}
		max = max > a ? max : a;
		max = max > b ? max : b;
	}
	int cnt = 0;
	for (int i = 0; i <= max; i++) {
		if (flag[i] && !ano_flag[i]) {
			cnt++;
			ano_flag[i] = true;
			dfs(i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
