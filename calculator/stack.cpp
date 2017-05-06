/*Amanda Ditmore
CS110C
3-20-2017*/

//function definitions for array-based stack class

#include "stack.h"


template<class ItemType>
Stack<ItemType>::Stack()
{
	max_size = 50;	
	top=0;
	arrayPtr = new ItemType[max_size];
} 

template<class ItemType>		
Stack<ItemType>::~Stack()
{
	delete [] arrayPtr;	
}
		

template<class ItemType>		
bool Stack<ItemType>::push(const ItemType newEntry )
//returns true if item successfully added to stack.
{ 
	bool success = true;
	if (top < max_size)
	{
		arrayPtr[top] = newEntry;
		++top;
	}
	else
	{
		success = false;
	}	
	return success;				
}


template<class ItemType>
bool Stack<ItemType>::pop()
//returns true if item successfully removed from stack
{
	bool success = true;
	if(top > 0)
	{
		--top;
	}
	else
	{
		success = false;
	}		
	return success;
}

template<class ItemType>
ItemType Stack<ItemType>::peek() const
//returns the item at the top of the stack
{
	return arrayPtr[top-1];
}

template class Stack<char>;
template class Stack<int>;
