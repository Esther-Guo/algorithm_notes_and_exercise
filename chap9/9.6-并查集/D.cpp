// http://codeup.cn/problem.php?cid=100000615&pid=3

/*
题目表述不太清楚，最终目标是选出人数最多的块。
注意union操作并不能将当前块内元素的父结点统一为根结点，如果此时需要寻找某元素的根结点，
仍应该使用findFather(x)而非father[x].
*/

#include <cstdio>

using namespace std;

const int maxn = 1000010;

int n, m;
int father[maxn];
int flag[maxn];

void init(int arr[]) {
    for (int i = 0; i < maxn; i++)
    {
        arr[i] = i;
        flag[i] = 0;
    }
}

int findFather(int x) {
    int temp = x;
    while (x != father[x]) {
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
    int fathera = findFather(a);
    int fatherb = findFather(b);
    if (fathera != fatherb) father[fathera] = fatherb;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        int a, b;
        init(father);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            union_ab(a, b);
        }
        for (int i = 1; i < maxn; i++) {
            flag[findFather(i)]++;
        }
        int max = 0;
        for (int i = 0; i < maxn; i++) {
            if (flag[i] > max) max = flag[i];
        }
        printf("%d\n", max);
    }
    return 0;
}

