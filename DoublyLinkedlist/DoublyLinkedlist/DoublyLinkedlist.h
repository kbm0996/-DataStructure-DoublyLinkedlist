#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

class DoublyLinkedlist
{
private:
	enum
	{
		en_MAX_LEN = 255
	};

	struct stNODE
	{
		char szData[en_MAX_LEN];

		stNODE *pNext;
		stNODE *pPrev;
	};

	stNODE _Head;
	stNODE _Tail;

public:
	DoublyLinkedlist();
	virtual ~DoublyLinkedlist() {}

	void push_front(char* szData);
	void push_back(char* szData);
	void Print();
	bool Delete(char* szData);

};
#endif