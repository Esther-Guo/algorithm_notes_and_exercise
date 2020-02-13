// http://codeup.cn/problem.php?cid=100000612&pid=1

/*

*/

#include <cstdio>
#include <map>

using namespace std;

int n, depth;

map<int, int> nodes; // 建立结点与当前高度的映射

int main() {
    while (scanf("%d", &n) != EOF) {
        nodes[1] = 1;
        depth = 1;
        int a, b;
        for (int i=0; i<n-1; i++) {
            scanf("%d %d", &a, &b);
            nodes[b] = nodes[a] + 1;
            if (nodes[b] > depth) depth = nodes[b];
        }
        printf("%d\n", depth);
    }
    return 0;
}

