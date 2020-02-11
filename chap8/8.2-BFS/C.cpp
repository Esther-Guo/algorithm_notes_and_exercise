// http://codeup.cn/problem.php?cid=100000609&pid=2

/*
像是我最怕的手机小游戏… 参考网上代码后采用BFS解决
*/

#include <cstdio>
#include <queue>

using namespace std;

int init[3][3], final[3][3];
// 上 下 左 右
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y;
    int step;
    int temp[3][3]; // 当前的分布
    int last[2]; // 上一步的位置，避免宽搜时再倒回去
}node;

// 检查越界
bool check(int x, int y) {
    if (x < 0 || x > 2 || y < 0 || y > 2) {
        return false;
    }
    else return true;
}

// 检查当前状态与最终状态是否相同
bool same(int temp[3][3], int final[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (temp[i][j] != final[i][j]) return false;
        }
    }
    return true;
}

int bfs(int x, int y) {
    // 初始为空格位置，视为第1步
    node.x = x;
    node.y = y;
    node.step = 1;
    // 没有上一步，初始化为本身
    node.last[0] = x;
    node.last[1] = y;
    // 拷贝最初始状态
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            node.temp[i][j] = init[i][j];
        }
    }
    queue<Node> q;
    q.push(node);
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            node.x = t.x + dx[i];
            node.y = t.y + dy[i];
            node.step = t.step + 1;
            // 不越界&&不会回到上一步
            if (check(node.x, node.y) && (node.x != t.last[0] || node.y!=t.last[1])) {
                // 记录上一步
                node.last[0] = t.x;
                node.last[1] = t.y;
                // 拷贝上一步状态并更改
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        node.temp[j][k] = t.temp[j][k];
                    }
                }
                int temp = node.temp[node.x][node.y];
                node.temp[node.x][node.y] = node.temp[t.x][t.y];
                node.temp[t.x][t.y] = temp;
                // 检查是否完成
                if (same(node.temp, final)) {
                    return node.step;
                }
                q.push(node);
            }
        }
    }
}

int main() {
    int x, y;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &init[i][j]);
            // 找到空格位置并标记为出发点(x,y)
            if (init[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &final[i][j]);
        }
    }
    int ans = bfs(x, y);
    printf("%d\n", ans);
    return 0;
}

