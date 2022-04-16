#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;
	Node* cur = NULL;
	Node* tail = NULL;

	Node* newNode = NULL;
	int readData;

	// 데이터를 입력 받는 과정
	while (1) {
		printf("자연수 입력 : ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		// 노드의 추가 과정(tail)
		/*
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;
		
		tail = newNode;
		*/

		// 노드의 추가 과정(head)
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL) 
			tail = newNode;
		else
			newNode->next = head;
		head = newNode;
		
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체출력! \n");
	
	cur = head;
	if (head == NULL)
		printf("저장된 자연수가 없습니다.\n");
	else
		printf("%d ", cur->data);
	while (cur->next != NULL) {
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n\n");

	// 메모리의 해제과정
	if (head == NULL) 
		return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d를 삭제합니다. \n", head->data);
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("%d를 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}