// http://codeup.cn/problem.php?cid=100000607&pid=3

/*
单链表翻转问题
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

Node* reverse(Node* head) {
	Node* p = head->next;
	Node* q;
	if (p->next != NULL) { // 至少有两个元素，否则无需翻转 
		q = p->next;
		p->next = NULL; // 第一个结点指向null 
		while (q != NULL) {
			if (q->next == NULL) { // 遍历至末尾，处理头结点 
				delete(head);
				head->next = q; // 令头结点重新指向首个元素 
				q->next = p; 
				break;
			}
			else { // 指向反向，并用temp暂存后一个元素 
				Node* temp = q->next;
				q->next = p;
				p = q;
				q = temp;
			}
		}
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
			Node* L2 = reverse(L);
			show(L2);
			printf("\n");
		}
		else {
			printf("list is empty\n");
		}
	}
    
    
    return 0;
}

