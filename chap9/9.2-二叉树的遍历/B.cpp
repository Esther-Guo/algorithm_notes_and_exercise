// http://codeup.cn/problem.php?cid=100000611&pid=1

/*

*/

#include <cstdio>

using namespace std;

int m, n;
int ans;

void count(int m) {
    if (m > n) return;
    if (m * 2 <= n) {
        ans++;
        count(m * 2);
    }
    if (m * 2 + 1 <= n) {
        ans++;
        count(m * 2 + 1);
    }
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m == 0 && n == 0) break;
        ans = 1;
        if (m == n) printf("%d\n", ans);
        else {
            count(m);
            printf("%d\n", ans);
        }
    }
    return 0;
}

