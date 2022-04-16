#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;
	NameCard *pcard;
	ListInit(&list);

	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pcard);

	// 한지영의 정보를 조회하여 출력
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "한지영"))
			ShowNameCardInfo(pcard);
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "한지영")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	else
		printf("No card\n\n");
	
	// 이진수의 정보를 조회하여 변경
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "이진수"))
			ChangePhoneNum(pcard, "010-9999-9999");
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "이진수")) {
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}
	else
		printf("No card\n\n");

	// 조수진의 정보를 조회하여 삭제
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "조수진")) {
			LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "조수진")) {
					LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}
	else
		printf("No card\n\n");

	// 남은 모든 사람의 전화번호 정보 출력
	if (LFirst(&list, &pcard)) {
		do {
			ShowNameCardInfo(pcard);
		} while (LNext(&list, &pcard));
	}

	return 0;
}