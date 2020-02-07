// http://codeup.cn/problem.php?cid=100000607&pid=0

/*
本题中包含许多增加删除操作，适合用链表实现。
使用cin及string类会时间超限。
基础操作的边界判断一定要考虑周全。
易出错情况： delete 0
            初始化链表为空(n=0)
*/

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct node {
    int data;
    node* next;
};

node* create(int n) {
    node *p, *pre; // p为当前结点，pre为当前结点的前一个结点
    node* head = new node;
    head->next = NULL;
    pre = head;
    for (int i=0; i<n; i++) {
        p = new node;
        scanf("%d", &p->data);
        p->next = pre->next;
        pre->next = p;
    }
    return head;
}

// 查询元素
void get(node* head, int pos) {
    node* p = head->next;
    int j=1;
    while (p != NULL && j<pos) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > pos) {
    	printf("get fail\n");
    	return;
    }
    else {
    	printf("%d\n", p->data);
    	return;
    }
    
}

// 插入元素
// 在第三个位置插入6，原序列53241，新序列536241
void insert(node* head, int pos, int x) {
    node* p = head;
    int j=0;
    while (p != NULL && j<pos-1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > pos-1) {
    	printf("insert fail\n");
    	return;
    }
    else {
    	node* q = new node; // 新建结点
    	q->data = x;
    	q->next = p->next;
    	p->next = q;
    	printf("insert OK\n");
    	return;
    }
    
}

void del(node* head, int pos) {
	node* pre = head;
	int j = 0;
	while (pre->next != NULL && j<pos-1) {
        pre = pre->next;
        j++;
    }
    if (pre->next == NULL || j > pos-1) {
    	printf("delete fail\n");
   		return;
   	}
	else {
		node* p = pre->next;
		pre->next = p->next;
    	delete(p);
    	printf("delete OK\n");
    	return;	
	}
    
}

void show(node* head) {
	node* L = head->next;
	if (L == NULL) printf("Link list is empty");
	bool flag = false;
	while (L != NULL) {
		flag? printf(" %d", L->data):printf("%d", L->data);
		flag = true;
		L = L->next;
	}
	printf("\n");
}

int main() {
	int n, m;
    scanf("%d", &n);
    node* L = create(n);
    scanf("%d", &m);
    char op[10];
    while (m--) {
    	scanf("%s", op);
    	if (strcmp(op, "show") == 0) show(L);
    	else if (strcmp(op, "get") == 0) {
    		int pos;
    		scanf("%d", &pos);
    		get(L, pos);
    	}
    	else if (strcmp(op, "delete") == 0) {
    		int pos;
    		scanf("%d", &pos);
    		del(L, pos);
    	}
    	else if (strcmp(op, "insert") == 0) {
    		int pos, x;
    		scanf("%d %d", &pos, &x);
    		insert(L, pos, x);
    	}
    }
    
    return 0;
}

