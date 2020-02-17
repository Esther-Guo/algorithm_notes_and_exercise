// http://codeup.cn/problem.php?cid=100000617&pid=4

/*
same as 9.7-C
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 30010;

int n, k;
int heap[maxn]; // 最小堆

// 将low结点的元素在[low, high]范围内调整至合适位置以满足最小堆
void adjustHeap(int low, int high) {
    int i = low;
    int j = i * 2; // 左子
    while (j <= high) {
        if (j + 1 <= high && heap[j] > heap[j + 1]) j = j + 1; // 存在右子且右子更小
        if (heap[i] > heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }
        else break;
    }
}

// 取出第一个元素
int getFirst() {
    int val = heap[1];
    // 减少元素移动，直接将最后面的元素放在堆顶，并向下调整堆
    swap(heap[1], heap[k]);
    k--;
    adjustHeap(1, k);
    return val;
}

// 新增元素
void insert(int x) {
    k++;
    heap[k] = x; // 放在最末
    // 向上调整
    // 因为插入前满足最小堆（根最小），因此不用考虑插入元素与左兄弟或右兄弟的大小关系，只考虑与根的关系
    int i = k;
    int j = i / 2;
    while (j >= 1) {
        if (heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }
        else break;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        k = n; // 记录堆内元素个数
        for (int i = 1; i <= n; i++) {
            scanf("%d", &heap[i]);
        }
        int ans = 0;
        if (n == 1) { // 只有一堆无需合并
            ans = heap[1];
        }
        else {
            // 建立小根堆
            for (int i = n / 2; i >= 1; i--) {
                adjustHeap(i, n);
            }
            int cnt = 0; // cnt代表合并次数（共n-1次）
            while (cnt < n - 1) {
                int first = getFirst();
                int second = getFirst();
                int sum = first + second;
                ans += sum;
                insert(sum);
                cnt++;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

// 优先队列实现哈弗曼树
#include <cstdio>
#include <queue>

using namespace std;

// 优先队列（小顶堆）
priority_queue <long long, vector<long long>, greater<long long>> q;

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        long long temp, x, y, ans = 0;
        for (int i=0; i<n ;i++) {
            scanf("%lld", &temp);
            q.push(temp);
        }
        while (q.size() > 1) { // 直到仅剩一个结点
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            q.push(x+y);
            ans += (x+y);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
