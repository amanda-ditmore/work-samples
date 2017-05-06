//header for heap class

#ifndef HEAP_CLASS_042017
#define HEAP_CLASS_042017


template <class ItemType>
class Heap
{
    private:
        static const int CHUNK_SIZE=8;
        ItemType *heapArray;
        int numItems;
        int maxItems;
        bool heapRebuild(int, ItemType*, int);
        void swap(int, int);
        
    public:
        //constructors and destructors:
        Heap() { numItems = 0; maxItems = CHUNK_SIZE; 
                 heapArray = new ItemType[CHUNK_SIZE]; }
        ~Heap() { delete [] heapArray; }
        //heap functions:
        int getNumItems() { return numItems; }
        ItemType peekTop() { return heapArray[0]; } //returns the root (maximum value item) of the heap
        bool isEmpty() { return numItems == 0; }
        bool add(ItemType);
        bool remove(); //removes the root (maximum value item) of the heap
        
       
};


#endif
