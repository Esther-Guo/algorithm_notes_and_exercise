// http://codeup.cn/problem.php?cid=100000615&pid=0

/*

*/

#include <cstdio>

const int maxn = 1010;

using namespace std;

int n, k;
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
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n == 0 && k == 0) break;
        int a, b;
        init(father, n);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &a, &b);
            union_ab(a, b);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (father[i] == i) cnt++;
        }
        if (cnt == 1 && n - 1 == k) printf("Yes\n"); // 顶点和边的关系必须满足n = k+1, 以确保不构成环
        else printf("No\n");
    }
    return 0;
}

