// http://codeup.cn/problem.php?cid=100000607&pid=3

/*
有个小坑，可以注意下
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

Node* process(Node* head) {
	Node* p = head->next;
	while (p != NULL) {
		Node* q = p->next;
		if (q == NULL) break;
		if (q->data == p->data) { // 如果是这种情况，p不用向后跳（即下个元素仍然和当前元素比较）
			p->next = q->next;
			delete(q);
		}
		else p = p->next;
	}
	return head;
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
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n) {
			Node* L = create(n);
			show(L);
			printf("\n");
			Node* L2 = process(L);
			show(L2);
			printf("\n");
		}
		else {
			printf("list is empty\n");
		}
	}
    return 0;
}

