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

	// �����͸� �Է� �޴� ����
	while (1) {
		printf("�ڿ��� �Է� : ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		// ����� �߰� ����(tail)
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

		// ����� �߰� ����(head)
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

	// �Է� ���� �������� ��°���
	printf("�Է� ���� �������� ��ü���! \n");
	
	cur = head;
	if (head == NULL)
		printf("����� �ڿ����� �����ϴ�.\n");
	else
		printf("%d ", cur->data);
	while (cur->next != NULL) {
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n\n");

	// �޸��� ��������
	if (head == NULL) 
		return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d�� �����մϴ�. \n", head->data);
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("%d�� �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}