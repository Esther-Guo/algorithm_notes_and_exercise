// http://codeup.cn/problem.php?cid=100000613&pid=1

/*

*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int n;
string init, comp;
string init_pre, init_in, comp_pre, comp_in;

struct Node {
    char data;
    Node* lchild;
    Node* rchild;
};

Node* newNode(char x) {
    Node* root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    return root;
}

void insert(Node* &root, char x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (root->data == x) return;
    else if (root->data > x) insert(root->lchild, x);
    else insert(root->rchild, x);
}

Node* create(string str) {
    Node* root = NULL;
    for (int i = 0; i < str.size(); i++) {
        insert(root, str[i]);
    }
    return root;
}

void preorder(Node* root, string& str) {
    if (root == NULL) return;
    str += root->data;
    preorder(root->lchild, str);
    preorder(root->rchild, str);
}

void inorder(Node* root, string& str) {
    if (root == NULL) return;
    inorder(root->lchild, str);
    str += root->data;
    inorder(root->rchild, str);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        cin >> init;
        Node* root = create(init);
        preorder(root, init_pre);
        inorder(root, init_in);
        for (int i = 0; i < n; i++) {
            cin >> comp;
            Node* root2 = create(comp);
            preorder(root2, comp_pre);
            inorder(root2, comp_in);
            if (init_pre == comp_pre && init_in == comp_in) printf("YES\n");
            else printf("NO\n");
            comp_pre = comp_in = ""; // 每组比较数据输出结果后记得初始化
        }
        init_pre = init_in = ""; // 每组数据处理完毕后记得初始化
    }
    return 0;
}

