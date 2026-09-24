#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define ERROR -1
#define NULL_LIST -2
#define NOT_FOUND -3
typedef struct Node {
	int data;
	struct Node* next;
}Node;
typedef Node* LinkList;

int free_list(LinkList* head) {
	if (head == NULL) {
		return NULL_LIST;
	}
	Node* cur = *head;
	while (cur != NULL) {
		Node* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*head = NULL;
	return OK;
}

void clear_input_line() {
	int c;
	while ((c = getchar())!='\n' && c != EOF);
}

LinkList create_from_head() {
	LinkList head = NULL;
	Node* node;
	int v;
	while (scanf("%d", &v) == 1) {
		node = (Node*)malloc(sizeof(Node));
		if (node == NULL) {
			printf("内存分配错误\n");
			free_list(&head);
			clear_input_line();
			return NULL;
		}
		node->data = v;
		node->next = head;
		head = node;
	}
	clear_input_line();
	return head;
}

LinkList create_from_tail() {
	LinkList head = NULL;
	Node* tail = NULL, * node;
	int v;
	while (scanf("%d", &v) == 1) {
		node = (Node*)malloc(sizeof(Node));
		if (node == NULL) {
			printf("内存分配错误\n");
			free_list(&head);
			clear_input_line();
			return NULL;
		}
		node->data = v;
		node->next = NULL;
		if (head == NULL) {
			head = tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
	}
	clear_input_line();
	return head;
}


int get_length(LinkList head) {
	if (head == NULL) {
		return NULL_LIST;
	}
	Node* cur = head;
	int len = 0;
	while (cur != NULL) {
		cur = cur->next;
		len++;
	}
	return len;
}

Node* locate_node(LinkList head, int index) {
	if (head == NULL) {
		return NULL;
	}
	if (index < 0) {
		return NULL;
	}
	Node* cur = head;
	for (int i = 0; cur != NULL && i < index; i++) {
		cur = cur->next;
	}
	return cur;
}

Node* get_node(LinkList head, int v, int* index) {
	if (head == NULL) {
		return NULL;
	}
	if (index == NULL) {
		return NULL;
	}
	int cnt = 0;
	Node* cur = head;
	while (cur != NULL && cur->data != v) {
		cur = cur->next;
		cnt++;
	}
	*index = cnt;
	return cur;
}

int insert_list(LinkList* head,int v,int index){
	if(head==NULL||*head==NULL){
		return NULL_LIST;
	}
	if(index<0){
		return ERROR;
	}
	if(index==0){
		Node*node=(Node*)malloc(sizeof(Node));
		node->data=v;
		node->next=*head;
		*head=node;
		return OK;
	}
	Node*prev=*head;
	for(int i=0;prev!=NULL&&i<index-1;i++){
		prev=prev->next;
	}
	if(prev==NULL){
		return ERROR;
	}
	Node*node=(Node*)malloc(sizeof(Node));
	if(node==NULL){
		printf("内存分配错误\n");
		return ERROR;
	}
	node->data=v;
	node->next=prev->next;
	prev->next=node;
	return OK;
}


int delete_list(LinkList* head,int index,int *value){
	if(head==NULL)return NULL_LIST;
	if(index<0)return ERROR;
	if(value==NULL)return ERROR;
	Node*pos=*head;
	if(index==0){
		Node*tmp=pos;
		pos=pos->next;
		*value=tmp->data;
		free(tmp);
		return OK;
	}
	Node*prev=head;
	for(int i=0;prev!=NULL&&i<index-1;i++){
		prev=prev->next;
	}
	if(prev==NULL||prev->next==NULL)return ERROR;
	Node*tmp=prev->next;
	*value=tmp->data;
	prev->next=tmp->next;
	free(tmp);
	return OK;
}

void difference_list(LinkList*listA,LinkList*listB){
	if(listA==NULL||*listA==NULL)return ;
	Node old_head;
	old_head.next=*listA;
	Node*cur=*listA,*prev=&old_head;
	while(cur!=NULL){
		Node*pos=*listB;
		int found=0;
		while(pos!=NULL){
			if(pos->data==cur->data){
				found=1;
				break;
			}
			pos=pos->next;
		}
		if(found){
			Node*tmp=cur;
			prev->next=tmp->next;
			cur=cur->next;
			free(tmp);
		}
		else{
			prev=cur;
			cur=cur->next;
		}
	}
	*listA=old_head.next;
	return ;
}

void display_list(LinkList head) {
	if (head == NULL) {
		printf("这是个空表\n");
		return;
	}
	size_t cnt = 0;
	printf("%-6s\t%-8s\t%-16s\t%-16s\n","ID","数据","下一地址","地址");
	Node* cur = head;
	while (cur != NULL) {
		cnt++;
		printf("%-4zu\t%-8d\t%-16p\t%-16p\n", cnt, cur->data, (void*)cur->next, (void*)cur);
        cur=cur->next;
	}
	return;
}

int main() {
	LinkList listA, listB;
	int value, index;

	printf("\n==========1、头插法创建链表==========\n");
	listA = create_from_head();
	display_list(listA);

    printf("\n==========2、尾插法创建链表==========\n");
    listB=create_from_tail();
    display_list(listB);

    printf("\n==========3、计算元素个数==========\n");
    int len=get_length(listA);
    printf("链表长度是：%d\n",len);

    printf("\n==========4、定位元素==========\n");
    Node*t=locate_node(listA,2);
    printf("获取第二个结点，数据：%d\n",t->data);


	printf("\n==========5、获取结点位置==========\n");
	t=get_node(listA,2,&index);
	printf("找到结点的位置：%d\n",index);
    
	printf("\n==========6、插入结点==========\n");
	insert_list(&listA,10,1);
	printf("插入结果：\n");
	display_list(listA);

	printf("\n==========7、删除结点==========\n");
	delete_list(&listB,2,&value);
	printf("删除数据：%d\n",value);
	printf("删除结果：");
	display_list(listB);
	

	printf("\n==========8、查重==========\n");
	difference_list(&listA,&listB);
	printf("查重结果入下：\n");
	display_list(listA);
	display_list(listB);

	return 0;

}
