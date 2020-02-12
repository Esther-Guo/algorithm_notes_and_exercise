// http://codeup.cn/problem.php?cid=100000611&pid=2

/*
create函数参考了网上代码。
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string pre;
int i;

struct Node {
    char data;
    Node* lchild;
    Node* rchild;
}*node;

Node* create() {
    char c = pre[i++];
    if (c == '#') return NULL; // 将当前结点设为null
    Node* root = new Node; // 否则开辟新结点准备插入
    root->data = c;
    root->lchild = create();
    root->rchild = create();
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->lchild);
    printf("%c ", root->data);
    inorder(root->rchild);
}

int main() {
    while (cin >> pre) {
        i = 0;
        node = create();
        inorder(node);
        printf("\n");
    }
    return 0;
}

