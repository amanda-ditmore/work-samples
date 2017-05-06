/*Amanda Ditmore
CS110C
4-1-2017*/

//Class header for array based queue

#ifndef ARRAY_BASED_QUEUE_42017
#define ARRAY_BASED_STACH_42017

template<class ItemType>
class Queue
{
	private:
		ItemType* arrayPtr;
		unsigned int front;
		unsigned int back;
		unsigned int max_size;

	public:
		Queue();		
		~Queue();
		bool isEmpty()
        //returns true if queue is empty
        {
	        return front == back;
        }
		bool enQ(ItemType);
        //returns true if item successfully added to queue
		bool deQ();
        //returns true if item successfully removed from queue
		ItemType peek();
        //returns the item at the top of the queue
};
#endif	
