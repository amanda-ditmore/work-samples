//function defs for heap class

#include "heap.h"
#include "patient.h"
#include <iostream>
using namespace std;

template <class ItemType>
bool Heap<ItemType>::add(ItemType newNode)
{
//adds an item to the heap with the add then rebuild strategy.
    //first checks max size and allocates memory if needed
    if (numItems == maxItems) 
    {
        maxItems+=CHUNK_SIZE;
		ItemType* newArray = new ItemType[maxItems];

        for( int i = 0; i < numItems; i++) 
        {
            newArray[i] = heapArray[i];
        }
        
        delete [] heapArray;
        heapArray = newArray;
    }

    //add item to next available position.
    heapArray[numItems] = newNode;
    bool inPlace = false;  
    int newNodeIndex = numItems, parentIndex;
    
    //trickles item up until in place. 
    while (!inPlace && newNodeIndex > 0)        
    {
        parentIndex = (newNodeIndex - 1)/2;
        if ( newNode > heapArray[parentIndex]) 
        {
            swap(newNodeIndex, parentIndex);
            newNodeIndex = parentIndex;
        }
        else
            inPlace = true;
    }
    ++numItems;
    return true;
}

template <class ItemType>
bool Heap<ItemType>::remove()
{
    if (isEmpty())
        return false;
    else
    {
        //copy item from bottom left position to root, then trickle down to proper position
        heapArray[0]=heapArray[numItems-1];
        --numItems;
        int largerChildIndex, rightChildIndex, outOfPlaceIndex=0;
        bool inPlace = false;
        //figure out which child is larger
        while (!inPlace) 
        {
            largerChildIndex=2*outOfPlaceIndex+1;
            if (largerChildIndex > numItems) 
            {
                inPlace = true;
            } 
            else
            {
                rightChildIndex=2*outOfPlaceIndex+2;
                if (rightChildIndex <=numItems && heapArray[rightChildIndex] > heapArray[largerChildIndex])
                {
                    largerChildIndex = rightChildIndex;
                }
            }
            //if the larger child is also larger than itme in question, swap them
            if (!inPlace && heapArray[largerChildIndex] > heapArray[outOfPlaceIndex] )
            {
                swap(largerChildIndex, outOfPlaceIndex);
                outOfPlaceIndex = largerChildIndex;
            } else {
                inPlace = true;
            }

        }
    }
}

template <class ItemType>
void Heap<ItemType>::swap(int posA, int posB) {
    ItemType temp;
    temp = heapArray[posA];
    heapArray[posA] = heapArray[posB];
    heapArray[posB] = temp;
}

template class Heap<int>;
template class Heap<Patient>;
