// http://codeup.cn/problem.php?cid=100000616&pid=1

/*
该算法参考网络，避免了数组过大，非常巧妙
1. 把(a1, bj), j = 1...n加入最小堆中（已有序）
2. 取出最小的那个(ai, bj)，把(ai+1, bj)加入堆中
3. 重复步骤2，n次以获取n个最小的和
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Node {
    int data;
    int i, j;
};

int n;
Node heap[maxn];
int A[maxn], B[maxn];

void adjustHeap() { // 将堆顶新元素向下调整
    int index = 1;
    int temp = index * 2;
    while (temp <= n) {
        if (temp+1 <= n && heap[temp].data > heap[temp + 1].data) temp = temp + 1;
        if (heap[index].data > heap[temp].data) {
            swap(heap[index], heap[temp]);
            index = temp;
            temp = index * 2;
        }
        else break;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
            heap[i].data = A[1] + B[i]; //步骤1
            heap[i].i = 1;
            heap[i].j = i;
        }
        int cnt = 0;
        while (cnt < n) { // 步骤2，3
            printf("%d ", heap[1].data);
            cnt++;
            int index_a = heap[1].i;
            int index_b = heap[1].j;
            heap[1].data = A[index_a + 1] + B[index_b];
            heap[1].i = index_a + 1;
            heap[1].j = index_b;
            adjustHeap();
        }
        printf("\n");
    }
    return 0;
}

