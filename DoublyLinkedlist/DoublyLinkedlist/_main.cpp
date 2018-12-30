#include "DoublyLinkedList.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	char chSelect;
	char szInData[255];

	DoublyLinkedlist list;

	while (1)
	{
		system("cls");
		printf("## MENU ##\n\nPrint : ");
		list.Print();
		printf("\n1. push_front \n2. push_back \n3. Delete\n\n");
		chSelect = _getch();

		switch (chSelect)
		{
		case '1':
			printf("Insert Data : ");
			gets_s(szInData, sizeof(szInData));
			list.push_front(szInData);
			break;
		case '2':
			printf("Insert Data : ");
			gets_s(szInData, sizeof(szInData));
			list.push_back(szInData);
			break;
		case '3':
			printf("Delete Data : ");
			gets_s(szInData, sizeof(szInData));
			if (list.Delete(szInData))
				printf("Delete Success\n");
			else
				printf("Delete Fail\n");
			break;
		}
	}
}