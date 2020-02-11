// http://codeup.cn/problem.php?cid=100000609&pid=3

/*
注意考虑初始态即为最终态的特情。每次循环后记得初始化哈希。
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int init[2][4] = { {1,2,3,4}, {8,7,6,5} }; // 初始状态
int final[2][4]; // 待输入最终状态
bool hashArr[100000000] = { false }; // 状态标记

struct Node {
    int arr[2][4]; // 当前状态
    vector<char> state; // 到达当前状态的操作记录
}node;

// 状态转哈希值
int funcHash(int arr[2][4]) {
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            sum = sum * 10 + arr[i][j]; // 其实*8就可以了
        }
    }
    return sum;
}

// 比较是否到达最终状态
bool same(int temp[2][4], int final[2][4]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (temp[i][j] != final[i][j]) return false;
        }
    }
    return true;
}

// 交换上下两行
Node funcA(Node node) {
    for (int i = 0; i < 4; i++) {
        int temp = node.arr[0][i];
        node.arr[0][i] = node.arr[1][i];
        node.arr[1][i] = temp;
    }
    return node;
}

// 将最右边的一列插入最左边
Node funcB(Node node) {
    int temp[2];
    temp[0] = node.arr[0][3];
    temp[1] = node.arr[1][3];
    for (int i = 3; i >= 1; i--) {
        node.arr[0][i] = node.arr[0][i - 1];
        node.arr[1][i] = node.arr[1][i - 1];
    }
    node.arr[0][0] = temp[0];
    node.arr[1][0] = temp[1];
    return node;
}

// 中央四格作顺时针旋转
Node funcC(Node node) {
    int temp = node.arr[0][1];
    node.arr[0][1] = node.arr[1][1];
    node.arr[1][1] = node.arr[1][2];
    node.arr[1][2] = node.arr[0][2];
    node.arr[0][2] = temp;
    return node;
}

// 输出操作序列
void out(vector<char> state) {
    int length = state.size();
    printf("%d\n", length);
    for (int i = 0; i < length; i++) {
        printf("%c", state[i]);
        if ((i + 1) % 60 == 0) printf("\n");
    }
    printf("\n");
}

void bfs() {
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            node.arr[i][j] = init[i][j];
            sum = sum * 10 + node.arr[i][j];
        }
    }
    // 初始状态即为目标
    if (same(node.arr, final)) {
        printf("0\n");
        return;
    }
    // 否则标记初始态
    hashArr[sum] = true;
    // 清空当前状态，避免下次循环时累计
    node.state.clear();
    queue<Node> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        Node copy = q.front(); // 记得拷贝一份便于后续三种不同操作均针对统一初始状态
        q.pop();
        // A
        node = funcA(node);
        sum = funcHash(node.arr);
        if (hashArr[sum] == false) {
            hashArr[sum] = true;
            node.state.push_back('A');
            if (same(node.arr, final)) {
                out(node.state);
                return;
            }
            q.push(node);
        }
        // B
        node = copy;
        node = funcB(node);
        sum = funcHash(node.arr);
        if (hashArr[sum] == false) {
            hashArr[sum] = true;
            node.state.push_back('B');
            if (same(node.arr, final)) {
                out(node.state);
                return;
            }
            q.push(node);
        }
        // C
        node = copy;
        node = funcC(node);
        sum = funcHash(node.arr);
        if (hashArr[sum] == false) {
            hashArr[sum] = true;
            node.state.push_back('C');
            if (same(node.arr, final)) {
                out(node.state);
                return;
            }
            q.push(node);
        }
    }
    return;
}

int main() {
    while (scanf("%d %d %d %d", &final[0][0], &final[0][1], &final[0][2], &final[0][3]) != EOF) {
        for (int i = 3; i >= 0; i--) {
            scanf("%d", &final[1][i]);
        }
        bfs();
        // 记得初始化哈希数组
        memset(hashArr, 0, sizeof(hashArr));
    }
    return 0;
}

