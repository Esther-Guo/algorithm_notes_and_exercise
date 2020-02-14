// http://codeup.cn/problem.php?cid=100000614&pid=0

/*
平衡二叉树基本操作
*/

#include <cstdio>

using namespace std;

int n, k;

struct Node {
    int data;
    int height;
    Node* lchild;
    Node* rchild;
};

Node* newNode(int x) {
    Node* root = new Node;
    root->data = x;
    root->height = 1;
    root->lchild = root->rchild = NULL;
    return root;
}

int getHeight(Node* root) {
    if (root == NULL) return 0;
    else return root->height;
}

int getBalanceFactor(Node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node* root) {
    int max_height = getHeight(root->lchild) > getHeight(root->rchild)? getHeight(root->lchild):getHeight(root->rchild);
    root->height = max_height + 1;
}

// 左旋
void L(Node*& root) {
    Node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

// 右旋
void R(Node*& root) {
    Node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

int search(Node* root, int x) {
    if (root == NULL) return 0;
    if (root->data == x) return 1;
    else if (root->data > x) search(root->lchild, x);
    else search(root->rchild, x);
}

void insert(Node* &root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    
    else if (root->data > x) {
        insert(root->lchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                R(root);
            }
            else if (getBalanceFactor(root->lchild) == -1) {
                L(root->lchild);
                R(root);
            }
        }
    }
    else {
        insert(root->rchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == 1) {
                R(root->rchild);
                L(root);
            }
            else if (getBalanceFactor(root->rchild) == -1) {
                L(root);
            }
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        int num;
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            insert(root, num);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &num);
            if (search(root, num)) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}

