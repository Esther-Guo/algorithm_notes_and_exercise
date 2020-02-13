// http://codeup.cn/problem.php?cid=100000613&pid=0

/*
包含二叉查找树基本操作
*/

#include <cstdio>

using namespace std;

int n;
int nums[110];

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

Node* newNode(int x) {
    Node* root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    return root;
}

void insert(Node* &root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (root->data == x) return;
    else if (root->data > x) insert(root->lchild, x); // 待插入数据小于当前根结点，插左边
    else insert(root->rchild, x);
}

Node* create() {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, nums[i]);
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        Node* root = create();
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
    }
    return 0;
}

