// http://codeup.cn/problem.php?cid=100000609&pid=4

/*
务必注意hash的对应关系，此处应该设置为init[0]进制，最大值可以达到100*pow(100,2)
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int init[3];
int k;
bool hashArr[1000000] = { false };

struct Node {
    int arr[3];
    int step; 
}node;

int funcHash(int arr[3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum = sum * init[0] + arr[i];
    }
    return sum;
}

bool end(int arr[3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i] == k) return true;
    }
    return false;
}

int bfs(Node node) {
    int sum = funcHash(node.arr);
    hashArr[sum] = true;
    // 0步完成
    if (end(node.arr)) {
        return 0;
    }
    queue<Node> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        Node copy = node;
        q.pop();
        // a->b
        if (node.arr[0] > 0 && node.arr[1] < init[1]) {
            if (node.arr[0] >= init[1] - node.arr[1]) {
                node.arr[0] -= (init[1] - node.arr[1]);
                node.arr[1] = init[1];
            }
            else {
                node.arr[1] += node.arr[0];
                node.arr[0] = 0;
            }
            node.step++;
            if (end(node.arr)) return node.step;
            sum = funcHash(node.arr);
            // 尚未经历才push
            if (hashArr[sum] == false) {
                hashArr[sum] = true;
                q.push(node);
            }
        }
        // a->c
        node = copy;
        if (node.arr[0] > 0 && node.arr[2] < init[2]) {
            if (node.arr[0] >= init[2] - node.arr[2]) {
                node.arr[0] -= (init[2] - node.arr[2]);
                node.arr[2] = init[2];
            }
            else {
                node.arr[2] += node.arr[0];
                node.arr[0] = 0;
            }
            node.step++;
            if (end(node.arr)) return node.step;
            sum = funcHash(node.arr);
            if (hashArr[sum] == false) {
                hashArr[sum] = true;
                q.push(node);
            }
        }
        // b->a
        node = copy;
        if (node.arr[1] > 0 && node.arr[0] < init[0]) {
            if (node.arr[1] >= init[0] - node.arr[0]) {
                node.arr[1] -= (init[0] - node.arr[0]);
                node.arr[0] = init[0];
            }
            else {
                node.arr[0] += node.arr[1];
                node.arr[1] = 0;
            }
            node.step++;
            if (end(node.arr)) return node.step;
            sum = funcHash(node.arr);
            if (hashArr[sum] == false) {
                hashArr[sum] = true;
                q.push(node);
            }
        }
        // b->c
        node = copy;
        if (node.arr[1] > 0 && node.arr[2] < init[2]) {
            if (node.arr[1] >= init[2] - node.arr[2]) {
                node.arr[1] -= (init[2] - node.arr[2]);
                node.arr[2] = init[2];
            }
            else {
                node.arr[2] += node.arr[1];
                node.arr[1] = 0;
            }
            node.step++;
            if (end(node.arr)) return node.step;
            sum = funcHash(node.arr);
            if (hashArr[sum] == false) {
                hashArr[sum] = true;
                q.push(node);
            }
        }
        // c->a
        node = copy;
        if (node.arr[2] > 0 && node.arr[0] < init[0]) {
            if (node.arr[2] >= init[0] - node.arr[0]) {
                node.arr[2] -= (init[0] - node.arr[0]);
                node.arr[0] = init[0];
            }
            else {
                node.arr[0] += node.arr[2];
                node.arr[2] = 0;
            }
            node.step++;
            if (end(node.arr)) return node.step;
            sum = funcHash(node.arr);
            if (hashArr[sum] == false) {
                hashArr[sum] = true;
                q.push(node);
            }
        }
        // c->b
        node = copy;
        if (node.arr[2] > 0 && node.arr[1] < init[1]) {
            if (node.arr[2] >= init[1] - node.arr[1]) {
                node.arr[2] -= (init[1] - node.arr[1]);
                node.arr[1] = init[1];
            }
            else {
                node.arr[1] += node.arr[2];
                node.arr[2] = 0;
            }
            node.step++;
            if (end(node.arr)) return node.step;
            sum = funcHash(node.arr);
            if (hashArr[sum] == false) {
                hashArr[sum] = true;
                q.push(node);
            }
        }
    }
    // 没有方案
    return -1;
}

int main() {
    while (scanf("%d %d %d %d", &init[0], &init[1], &init[2], &k) != EOF) {
        node.arr[0] = init[0];
        node.arr[1] = node.arr[2] = 0;
        node.step = 0;
        int ans = bfs(node);
        if (ans == -1) printf("no\n");
        else {
            printf("yes\n");
            printf("%d\n", ans);
        }
        memset(hashArr, 0, sizeof(hashArr));
    }
    return 0;
}

