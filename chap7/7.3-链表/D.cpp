// http://codeup.cn/problem.php?cid=100000607&pid=3

/*

*/

#include <cstdio>

using namespace std;

struct Node {
    int data;
	Node* next;
};

Node* create(int n) {
	Node* p;
	Node* head = new Node;
	head->next = NULL;
	p = head;
	while (n--) {
		int num;
		Node* q = new Node;
		scanf("%d", &num);
		q->data = num;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head;
}

void swap(Node* pre) {
	Node* p = pre->next;
	Node* q = p->next;
	if (q!=NULL) {
		pre->next = q;
		p->next= q->next;
		q->next = p;
	} 
}

int find(Node* head, int x) {
	Node* pre = head;
	Node* p = head->next;
	int j=1;
	while (p != NULL) {
		if (p->data == x) {
			swap(pre);
			return 0;
		}
		else if (p->data >= x) {
			return j;
		}
		pre = p;
		p = p->next;
		j++;
	}
	return j;
}

void insert(Node* head, int pos, int x) {
	Node* pre = head;
	for (int i=0; i<pos-1;i++) {
		pre = pre->next;
	}
	Node* p = new Node;
	p->data = x;
	p->next = pre->next;
	pre->next = p;
}

void show(Node* head) {
	Node* p = head->next;
	bool flag = false;
	while (p!=NULL) {
		flag? printf(" %d", p->data):printf("%d", p->data);
		flag = true;
		p = p->next;
	}
}

int main() {
	int n, x;
	while (scanf("%d %d", &x, &n) != EOF) {
		Node* L = create(n);
		int val = find(L, x);
		if (val) {
			printf("no\n");
			insert(L, val, x);
		}
		show(L);
		printf("\n");
	}
    
    
    return 0;
}

