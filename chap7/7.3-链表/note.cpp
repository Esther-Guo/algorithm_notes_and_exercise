// 本书中（动态）链表均有头结点，且头结点没有存储数据

// 创建链表(将五个元素的数组存入链表)
#include <cstdio>

struct node {
    int data;
    node* next;
};

node* create(int array[]) {
    node *p, *pre; // p为当前结点，pre为当前结点的前一个结点
    node* head = new node;
    head->next = NULL;
    pre = head;
    for (int i=0; i<5; i++) {
        p = new node;
        p->data = array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int main() {
    int array[5] = {5, 3, 2, 4, 1};
    node* L = create(array);
    L = L->next; // 跳过头结点
    while (L != NULL) {
        printf("%d ", L->data);
        L = L->next;
    }
    return 0;
}

// 查询元素
int search(node* head, int x) {
    int count = 0;
    node* p = head->next;
    while (p != NULL) {
        if (p->data == x) count++;
        p = p->next;
    }
    return count;
}

// 插入元素
// 在第3个位置插入6，原序列53241，新序列536241
void insert(node* head, int pos, int x) {
    node* p = head;
    for (int i=0; i<pos-1; i++) {
        p = p->next;
    }
    node* q = new node; // 新建结点
    q->data = x;
    q->next = p->next;
    p->next = q;
}

// 删除元素
// 删除所有值为x的结点
void del(node* head, int x) {
    node* p = head->next;
    node* pre = head;
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next;
            delete(p); // p指向NULL，原地址存储的内容被释放
            p = pre->next; // 再次使p指向当前结点
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}

// 静态链表（没有头结点）
// hash，建立结构体数组，使用下标（相当于结点的地址）访问结点。可以使用-1表示NULL
