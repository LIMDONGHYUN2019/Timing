#pragma once

template  <typename T>
class CNode
{
	template<typename T>
	friend class CList;
	template<typename T>
	friend class CIterator;

public:
	CNode()
	{
		pPrev = nullptr;
		pNext = nullptr;
	}
	~CNode()
	{

	}

	typedef CNode<T> Node;
	typedef CNode<T>* pNode;
	
private:
	T Data;
	pNode pPrev; 
	pNode	pNext;
};

template<typename T>
class CIterator
{
	template <typename T>
	friend class CList;

public:
	CIterator()
	{
		_pnode = nullptr;
	}
	~CIterator()
	{

	}
	typedef CIterator<T> iterator;
	typedef CNode<T> Node;
	typedef CNode<T>* pNode;

private:
	pNode _pnode;

public:
	bool operator ==(const iterator& iter)
	{
		return _pnode == iter._pnode;
	}
	bool operator != (const iterator& iter)
	{
		return _pnode != iter._pnode;
	}

	void operator ++()
	{
		_pnode = _pnode->pNext;
	}
	void operator ++(int)
	{
		_pnode = _pnode->pNext;
	}
	void operator --()
	{
		_pnode = _pnode->pPrev;
	}
	void operator --(int)
	{
		_pnode = _pnode->pPrev;
	}
	T& operator *()
	{
		return _pnode->Data;
	}
};

template<typename T>
class CList
{
public:
	CList()
	{
		_Begin = new Node;
		_End = new Node;
		_Begin->pNext = _End;
		_End->pPrev = _Begin;
		iSize = 0;
	}
	~CList()
	{
		pNode Delete_Node = _Begin;
		while (Delete_Node)
		{
			pNode Delete_Next = Delete_Node->pNext;

			delete Delete_Node;

			Delete_Node = Delete_Next;
		}
	}

	//typedef struct CNode
	//{
	//	T Data;
	//	pNode pPrev;
	//	pNode	pNext;
	//}*pNode, Node;


	typedef CIterator<T> iterator;
	typedef CNode<T> Node;
	typedef  CNode<T>* pNode;


private:
	pNode _Begin;
	pNode _End;
	int iSize;


public:
	void Push_Front(const T& data)
	{
		pNode Save = new Node;
		Save->Data = data;

		pNode Tempo = _Begin->pNext;
		Save->pNext = Tempo;
		Tempo->pPrev = Save;

		_Begin->pNext = Save;
		Save->pPrev = _Begin;

		iSize++;
	}
	void Push_Back(const T& data)
	{
		pNode Save = new Node;
		Save->Data = data;

		pNode Tempo = _End->pPrev;
		Save->pNext = _End;
		_End->pPrev = Save;

		Save->pPrev = Tempo;
		Tempo->pNext = Save;

		iSize++;
	}

	void Pop_Front()
	{
		if (!empty())
		{
			return;
		}

		pNode Delete_Node = _Begin->pNext;
		pNode Delete_Next = Delete_Node->pNext;

		_Begin->pNext = Delete_Next;
		Delete_Next->pPrev = _Begin;

		delete Delete_Node;
		iSize--;
	}
	void Pop_Back()
	{
		if (!empty())
		{
			return;
		}

		pNode Delete_Node = _End->pPrev;
		pNode Delete_Prev = Delete_Node->pPrev;

		_End->pPrev = Delete_Prev;
		Delete_Prev->pNext = _End;

		delete Delete_Node;

		iSize--;
	}

	bool empty()	const
	{
		return iSize == 0;
	}

	int size()	const
	{
		return iSize;
	}

	void clear()
	{
		if (empty())
			return;

		pNode Delete_Node = _Begin->pNext;

		while (Delete_Node != _End)
		{
			pNode Delete_Next = Delete_Node->pNext;

			delete Delete_Node;

			Delete_Node = Delete_Next;
		}

		iSize = 0;
		_Begin->pNext = _End;
		_End->pPrev = _Begin;
	}

	iterator begin()		const
	{
		iterator iter;
		iter._pnode = _Begin->pNext;
		return iter;
	}
	iterator End()	const
	{
		iterator iter;
		iter._pnode = _End;
		return iter;
	}


	iterator erase(iterator& iter)
	{
		pNode Delete_Prev = iter._pnode->pPrev;
		pNode Delete_Next = iter._pnode->pNext;

		Delete_Prev->pNext = Delete_Next;
		Delete_Next->pPrev = Delete_Prev;

		delete iter._pnode;
		iSize--;

		iter._pnode = Delete_Next;
		return iter;
	}

	iterator erase(const T& data)
	{
		iterator iter;
		iterator end = End();
		for (iter = begin(); iter != end; iter++)
		{
			if (*iter == data)
			{
				return erase(iter);
			}
		}
	}

	iterator find(const T& data)
	{
		iterator iter;
		iterator end = End();
		for (iter = begin(); iter != end; iter++)
		{
			if (*iter == data)
			{
				return iter;
			}
		}
		return end;
	}

	bool Check(const T& data)	const
	{
		return find(data) != data;
	}

	void sort()	const
	{
		iterator iter;
		iterator iterend = End();
		iterend--;

		for (iter = begin(); iter != iterend; iter++)
		{
			iterator iter2 = iter;
			iter2++;
			iterator iter2end = End();

			for (; iter2 != iter2end; iter2++)
			{
				if (*iter > * iter2)
				{
					T temp = *iter;
					*iter = *iter2;
					*iter2 = temp;
				}
			}
		}
	}
};