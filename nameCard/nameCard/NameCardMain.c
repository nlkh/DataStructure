#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;
	NameCard *pcard;
	ListInit(&list);

	pcard = MakeNameCard("������", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "010-3333-7777");
	LInsert(&list, pcard);

	// �������� ������ ��ȸ�Ͽ� ���
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������"))
			ShowNameCardInfo(pcard);
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "������")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	else
		printf("No card\n\n");
	
	// �������� ������ ��ȸ�Ͽ� ����
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������"))
			ChangePhoneNum(pcard, "010-9999-9999");
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "������")) {
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}
	else
		printf("No card\n\n");

	// �������� ������ ��ȸ�Ͽ� ����
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "������")) {
					LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}
	else
		printf("No card\n\n");

	// ���� ��� ����� ��ȭ��ȣ ���� ���
	if (LFirst(&list, &pcard)) {
		do {
			ShowNameCardInfo(pcard);
		} while (LNext(&list, &pcard));
	}

	return 0;
}