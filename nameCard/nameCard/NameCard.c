#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// Namecard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* namecard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(namecard->name, 30, name);
	strcpy_s(namecard->phone, 30, phone);

	return namecard;
}

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard) {
	printf("Name : %s\n", pcard->name);
	printf("Phone : %s\n\n", pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, char* phone) {
	pcard->phone[0] = 0;
	strcpy_s(pcard->phone, 30, phone);
}