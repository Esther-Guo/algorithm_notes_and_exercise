// http://codeup.cn/problem.php?cid=100000608&pid=5

/*
晕晕乎乎做出来了，思路还是不够清晰。
*/

#include <cstdio>
#include <cstring>

int a[16][16]; // 记录迷宫
int b[16][16] = { 0 }; // 记录已经过的点
int n, m; // m行n列
int s1, s2, e1, e2; // 起点终点
int p[230][2]; // 记录路线上的点，230>15*15
int cnt = 0; // 路线长度，用于打印路线
bool flag = false; // 是否有可行路线

void search(int s1, int s2, int b[16][16], int p[230][2]) {
    if (s2 > 1 && b[s1][s2 - 1] == 0 && a[s1][s2 - 1] == 1) { // left
        // 加入路线
        p[cnt][0] = s1;
        p[cnt++][1] = s2 - 1;
        // 到达终点
        if (s1 == e1 && s2 - 1 == e2) {
            flag = true;
            for (int i = 0; i < cnt; i++) {
                i ? printf("->(%d,%d)", p[i][0], p[i][1]) : printf("(%d,%d)", p[i][0], p[i][1]);
            }
            printf("\n");
            // 后退，当前点初始化标记
            b[s1][s2] = 0;
            cnt -= 2; // -2包括终点和当前点
            return;
        }
        // 下个点不是终点
        else {
            b[s1][s2 - 1] = 1; // 标记经过
            search(s1, s2 - 1, b, p); // 在下个点寻找路线 
        }
    }
    if (s1 > 1 && b[s1 - 1][s2] == 0 && a[s1 - 1][s2] == 1) { // up
        p[cnt][0] = s1 - 1;
        p[cnt++][1] = s2;
        if (s1 - 1 == e1 && s2 == e2) {
            flag = true;
            for (int i = 0; i < cnt; i++) {
                i ? printf("->(%d,%d)", p[i][0], p[i][1]) : printf("(%d,%d)", p[i][0], p[i][1]);
            }
            printf("\n");
            b[s1][s2] = 0;
            cnt -= 2;
            return;
        }
        else {
            b[s1 - 1][s2] = 1; 
            search(s1 - 1, s2, b, p);
        }
    }
    if (s2 < n && b[s1][s2 + 1] == 0 && a[s1][s2 + 1] == 1) { // right
        p[cnt][0] = s1;
        p[cnt++][1] = s2 + 1;
        if (s1 == e1 && s2 + 1 == e2) {
            flag = true;
            for (int i = 0; i < cnt; i++) {
                i ? printf("->(%d,%d)", p[i][0], p[i][1]) : printf("(%d,%d)", p[i][0], p[i][1]);
            }
            printf("\n");
            b[s1][s2] = 0;
            cnt-=2;
            return;
        }
        else {
            b[s1][s2 + 1] = 1;
            search(s1, s2 + 1, b, p);
        }
    }
    if (s1 < m && b[s1 + 1][s2] == 0 && a[s1 + 1][s2] == 1) { // down
        p[cnt][0] = s1 + 1;
        p[cnt++][1] = s2;
        if (s1 + 1 == e1 && s2 == e2) {
            flag = true;
            for (int i = 0; i < cnt; i++) {
                i ? printf("->(%d,%d)", p[i][0], p[i][1]) : printf("(%d,%d)", p[i][0], p[i][1]);
            }
            printf("\n");
            b[s1][s2] = 0;
            cnt -= 2;
            return;
        }
        else {
            b[s1 + 1][s2] = 1;
            search(s1 + 1, s2, b, p);
        }
    }
    b[s1][s2] = 0; // 四个方向均否定，继续回退
    cnt--;
    return;
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d %d", &s1, &s2);
        scanf("%d %d", &e1, &e2);
        // 路线起点初始化，并在b中标记
        p[cnt][0] = s1;
        p[cnt++][1] = s2;
        b[s1][s2] = 1;
        // dfs
        search(s1, s2, b, p);
        // 没有可行路线
        if (!flag) printf("-1\n");
    }
    return 0;
}

