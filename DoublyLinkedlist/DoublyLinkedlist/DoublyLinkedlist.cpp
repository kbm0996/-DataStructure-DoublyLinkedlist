#include "DoublyLinkedList.h"
#include <Windows.h>
#include <stdio.h>

DoublyLinkedlist::DoublyLinkedlist()
{
	_Head.pNext = &_Tail;
	_Head.pPrev = NULL;
	_Tail.pNext = NULL;
	_Tail.pPrev = &_Head;
}

void DoublyLinkedlist::push_front(char* szData)
{
	stNODE *pNode = (stNODE*)malloc(sizeof(stNODE));

	memcpy(pNode->szData, szData, sizeof(pNode->szData));

	pNode->pPrev = &_Head;
	pNode->pNext = _Head.pNext;
	pNode->pPrev->pNext = pNode;
	pNode->pNext->pPrev = pNode;
}

void DoublyLinkedlist::push_back(char* szData)
{
	stNODE *pNode = (stNODE*)malloc(sizeof(stNODE));

	memcpy(pNode->szData, szData, sizeof(pNode->szData));

	pNode->pPrev = _Tail.pPrev;
	pNode->pNext = &_Tail;
	pNode->pPrev->pNext = pNode;
	pNode->pNext->pPrev = pNode;
}

void DoublyLinkedlist::Print()
{
	stNODE *pNode = _Head.pNext;;

	while (pNode->pNext != NULL)
	{
		printf("[%s] ", pNode->szData);
		pNode = pNode->pNext;
	}
	printf("\n");
}

bool DoublyLinkedlist::Delete(char* szData)
{
	stNODE *pNode = _Head.pNext;

	while (pNode->pNext != NULL)
	{
		if (strcmp(pNode->szData, szData) == 0)
		{
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			free(pNode);
			return true;
		}
		pNode = pNode->pNext;
	}
	return false;
}