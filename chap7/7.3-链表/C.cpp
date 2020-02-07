// http://codeup.cn/problem.php?cid=100000607&pid=2

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

Node* end(Node* head) {
	Node* p = head;
	while (p->next != NULL) p = p->next;
	return p;
}

void show(Node* head) {
	Node* p = head->next;
	bool flag = false;
	while (p!=head) {
		flag? printf(" %d", p->data):printf("%d", p->data);
		flag = true;
		p = p->next;
	}
}

int main() {
	int n, m;
	while (scanf("%d", &m) != EOF) {
		Node* L1 = create(m);
		Node* E1 = end(L1);
		scanf("%d", &n);
		Node* L2 = create(n);
		Node* E2 = end(L2);
		E2->next = L1;
		E1->next = L2->next;
		show(L1);
		printf("\n");
	}
    
    
    return 0;
}

