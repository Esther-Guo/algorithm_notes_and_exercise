// http://codeup.cn/problem.php?cid=100000612&pid=0

/*

*/

#include <cstdio>
#include <cmath>

using namespace std;

int nodes[1010];
int n, depth;

int main() {
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &nodes[i]);
        }
        scanf("%d", &depth);
        int index = (int)pow(2.0, depth - 1);
        int end = index * 2 - 1;
        if (index > n) printf("EMPTY\n");
        else {
            while (index <= end) {
                if (index == end) printf("%d", nodes[index]);
                else printf("%d ", nodes[index]);
                index++;
            }
            printf("\n");
        }
    }
    return 0;
}

