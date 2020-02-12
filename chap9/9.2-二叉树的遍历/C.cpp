// http://codeup.cn/problem.php?cid=100000611&pid=2

/*
same as A
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string pre, in;
int preL, preR, inL, inR;

struct Node {
    char data;
    Node* lchild;
    Node* rchild;
}*node;

Node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }
    Node* root = new Node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL; // 左子树结点数
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%c", root->data);
}

int main() {
    while (cin >> pre >> in) {
        preL = inL = 0;
        preR = pre.size() - 1;
        inR = in.size() - 1;
        node = create(preL, preR, inL, inR);
        postorder(node);
        printf("\n");
    }
    return 0;
}

