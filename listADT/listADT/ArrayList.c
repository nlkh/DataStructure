#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{	
	plist->numofData = 0;
	plist->curPosition = 0;
}

void LInsert(List* plist, LData data)
{
	if (plist->numofData >= LIST_LEN)
		return;
	plist->arr[plist->numofData] = data;
	(plist->numofData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numofData < 1)
		return FALSE;
	plist->curPosition = 0;
	*pdata = (plist->arr[plist->curPosition]);
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition + 1 >= plist->numofData)
		return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int i = 0;
	LData removeData;

	if (plist->numofData < 1)
		return FALSE;

	removeData = plist->arr[plist->curPosition];

	for (i = plist->curPosition; i < plist->numofData-1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numofData)--;
	(plist->curPosition)--;

	return removeData;
}

int LCount(List* plist)
{
	return plist->numofData;
}