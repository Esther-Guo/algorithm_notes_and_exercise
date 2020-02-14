// http://codeup.cn/problem.php?cid=100000616&pid=0

/*
大根堆，递增堆排序
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int n;
int heap[maxn];

void downAdjust(int low, int high) {
    int i = low, j = i * 2; // i为待调整结点，j为其左子结点
    while (j <= high) { //存在左子结点
        if (j + 1 <= high && heap[j + 1] > heap[j]) { // 存在右子结点且比左子大
            j = j + 1; // 右子上场
        }
        if (heap[j] > heap[i]) { // 子>父
            swap(heap[j], heap[i]);
            i = j; // 继续向下比较直到没有子结点
            j = i * 2;
        }
        else break; // 无需交换
    }
}

void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

void sortHeap() {
    for (int i = n; i > 1; i--) { // 倒序遍历直到只剩一个元素
        swap(heap[i], heap[1]); // 不断将最后一个元素和堆顶元素交换，此时最后一个元素即为当前最大
        downAdjust(1, i - 1); // 调整堆顶元素到合适位置（此时考虑的序列不包含刚刚交换到最后的元素）
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &heap[i]);
        }
        createHeap();
        sortHeap();
        for (int i = 1; i <= n; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }
    return 0;
}

