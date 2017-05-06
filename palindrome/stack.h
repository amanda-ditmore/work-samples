/*Amanda Ditmore
CS110C
3-20-2017*/

//Class header for array based stack

#ifndef ARRAY_BASED_STACK_32017
#define ARRAY_BASED_STACH_32017	

template<class ItemType>
class Stack
{
	private:
		ItemType* arrayPtr;
		unsigned int top;
		unsigned int max_size;
	public:	
		
		Stack();
		~Stack();

		bool isEmpty() const
		//returns true if stack is empty
		{
			return top==0;
		}

		bool push(const ItemType newEntry );
		//returns true if item successfully added to stack. 				

		bool pop();
		//returns true if item successfully removed from stack

		ItemType peek() const;
		//returns the item at the top of the stack (position in array[top - 1])
	
};

#endif
