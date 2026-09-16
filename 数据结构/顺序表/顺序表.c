#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 100
#define NULL_LIST -1
#define OK 0
#define ERROR -2
#define NOT_FOUND -3
typedef struct SeqList {
	int data[MAX_SIZE];
	int length;
}SeqList;

int initList(SeqList* list) {
	if (list == NULL) {
		return NULL_LIST;
	}
	list->length = 0;
	return OK;
}

int creatList(SeqList* list) {
	if (list == NULL) {
		return NULL_LIST;
	}
	int v;
	while (scanf("%d", &v) == 1) {
		if (list->length >= MAX_SIZE) {
			break;
		}
		list->data[list->length] = v;
		list->length++;
	}
	return OK;
}

int insertList(SeqList* list, const int index, const int data) {
	if (list == NULL) {
		return NULL_LIST;
	}
	if (index<0 || index>list->length) {
		return ERROR;
	}
	if (list->length >= MAX_SIZE) {
		return ERROR;
	}
	for (int i = list->length - 1; i >= index; i++) {
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = data;
	list->length++;
	return OK;
}

int deleteList(SeqList* list, const int index, int* data) {
	if (list == NULL || data == NULL) {
		return NULL_LIST;
	}
	if (list->length <= 0) {
		return ERROR;
	}
	if (index < 0 || index >= list->length) {
		return ERROR;
	}
	*data = list->data[index];
	for (int i = index; i < list->length - 1; i++) {
		list->data[i] = list->data[i + 1];
	}
	list->length--;
	return OK;
}


int locate(SeqList* list, int data) {
	if (list == NULL) {
		return NULL_LIST;
	}
	if (list->length <= 0) {
		return NULL_LIST;
	}
	for (int i = 0; i < list->length; i++) {
		if (list->data[i]==data) {
			return i;
		}
	}
	return NOT_FOUND;
}

int displayList(SeqList* list) {
	if (list == NULL) {
		return NULL_LIST;
	}
	if (list->length == 0) {
		printf("这是个空链表！\n");
	}
	else {
		for (int i = 0; i < list->length; i++) {
			printf("[%4d] %6d\n", i, list->data[i]);
		}
	}
	return OK;
}

int getData(const SeqList* list, int index, int* data) {
	if (list == NULL||list->length==0) {
		return NULL_LIST;
	}
	if (index < 0 || index >= list->length) {
		return ERROR;
	}
	*data = list->data[index];
	return OK;
}

int bubblesort(SeqList* list) {
	if (list == NULL) {
		return NULL_LIST;
	}
	int size = list->length;
	for (int i = size; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			if (list->data[j-1] > list->data[j]) {
				int tmp = list->data[j-1];
				list->data[j-1] = list->data[j];
				list->data[j] = tmp;
			}
		}
	}
	return OK;
}

int mergeList(SeqList* listA, SeqList* listB, SeqList* listC) {
	if (listA == NULL || listB == NULL) {
		return NULL_LIST;
	}
	initList(listC);
	bubblesort(listA);
	bubblesort(listB);
	if (listA->length + listB->length > MAX_SIZE) {
		return ERROR;
	}
	int i = 0, j = 0;
	while (i < listA->length && j < listB->length) {
		if (listA->data[i] < listB->data[j]) {
			listC->data[listC->length] = listA->data[i];
			i++;
		}
		else {
			listC->data[listC->length] = listB->data[j];
			j++;
		}
		listC->length++;
	}
	while (i < listA->length) {
		listC->data[listC->length] = listA->data[i];
		i++;
		listC->length++;
	}
	while (j < listB->length) {
		listC->data[listC->length] = listB->data[j];
		j++;
		listC->length++;
	}
	return OK;
}

