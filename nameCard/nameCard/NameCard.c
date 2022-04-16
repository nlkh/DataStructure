#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// Namecard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* namecard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(namecard->name, 30, name);
	strcpy_s(namecard->phone, 30, phone);

	return namecard;
}

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard* pcard) {
	printf("Name : %s\n", pcard->name);
	printf("Phone : %s\n\n", pcard->phone);
}

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
}

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard* pcard, char* phone) {
	pcard->phone[0] = 0;
	strcpy_s(pcard->phone, 30, phone);
}