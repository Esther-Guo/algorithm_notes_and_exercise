// http://codeup.cn/problem.php?cid=100000609&pid=1

/*
48行很关键，要考虑石头的移动
*/

#include <cstdio>
#include <queue>

using namespace std;

char a[8][9];
// 不动 上 下 左 右 左上 右上 左下 右下
int dx[] = {0, -1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 0, -1, 1, -1, 1, -1, 1};
bool flag;

struct Node {
    int x, y;
    int step;
}s, temp;

// 检查是否越界
bool check(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        return false;
    }
    else return true;
}

void bfs() {
    // 起始点
    s.x = 7;
    s.y = 0;
    s.step = 0;
    // 初始化队列
    queue<Node> q;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        // 遍历九个动作
        for (int i = 0; i < 9; i++) {
            temp.x = s.x + dx[i];
            temp.y = s.y + dy[i];
            temp.step = s.step + 1;
            // 未出界 && 该位置没有石头 && 该位置的上方没有石头
            if (check(temp.x, temp.y) && a[temp.x - temp.step][temp.y] != 'S' && a[temp.x-temp.step+1][temp.y] != 'S') {
                // 到终点 || 走了8步（石头全部消失）
                if (a[temp.x][temp.y] == 'A' || temp.step == 8) {
                    flag = 1;
                    return;
                }
                q.push(temp);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%s", a[j]);
        }
        flag = 0;
        bfs();
        printf("Case #%d: ", i);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

