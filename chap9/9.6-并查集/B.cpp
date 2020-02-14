// http://codeup.cn/problem.php?cid=100000615&pid=1

/*

*/

#include <cstdio>

const int maxn = 1010;

using namespace std;

int n, m;
int father[maxn];

void init(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

int findFather(int x) {
    int temp = x;
    while (x != father[x]) { // 执行完毕后x为根结点
        x = father[x];
    }
    while (temp != father[temp]) {
        int a = temp;
        temp = father[temp];
        father[a] = x;
    }
    return x;
}

void union_ab(int a, int b) {
    int fatherA = findFather(a);
    int fatherB = findFather(b);
    if (fatherA != fatherB) father[fatherA] = fatherB;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        scanf("%d", &m);
        int a, b;
        init(father, n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            union_ab(a, b);
        }
        int cnt = 0; // 块数
        for (int i = 0; i < n; i++) {
            if (father[i] == i) cnt++;
        }
        printf("%d\n", cnt-1); // 所有块连在一起
    }
    return 0;
}

