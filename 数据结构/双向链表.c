#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {
	int val;
	struct Node* next;            //在c语言里面，结构体的指针类型必须加上struct，跟c++不一样，c++可以直接使用Node*
	struct Node* prev;
};


struct Node* creatlist() {                //创建链表，先创建头节点，然后在后面采用push_back的方法连接后面的节点
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	if (head == NULL) {
		printf("内存分配错误\n");
		return NULL;
	}
	head->next = NULL;              //接的头节点的前后两个节点都要指向NULL
	head->prev = NULL;
	return head;
}

struct Node* Push_back(struct Node*head,int x) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));      //先创建一个节点存储当前的值
	newnode->val = x;
	newnode->next = NULL;
	struct Node* cur = head;
	while (cur->next != NULL) {             //循环找到链表的最后一个节点
		cur = cur->next;
	}
	cur->next = newnode;                   //将当前节点的下一个节点连接上新创建的节点
	newnode->prev = cur;                   //将新创建的节点的prev指针指向当前cur节点
	return head;
}

int main() {
	struct Node* head = creatlist();
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf_s("%d", &x);
		Push_back(head, x);
	}
	struct Node* pos = head->next;
	while (pos != NULL) {
		printf("%d ", pos->val);
		pos = pos->next;
	}
	printf("\n");
	struct Node* cur = head;
	while (cur->next != NULL) {          //逆序输出链表的内容
		cur = cur->next;
	}
	while (cur != head) {
		printf("%d ", cur->val);
		cur = cur->prev;
	}
	printf("\n");
	return 0;
}