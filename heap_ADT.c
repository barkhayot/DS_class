#include "heap_ADT.h"
#include <math.h>
#include <stdlib.h>

/* heapCreate
  --------------
  Allocates memory for heap and return address of heap head structure.
  Pre. Nothing
  Post. heap created and address returned
        if memory overflow, NULL returned
*/
HEAP* heapCreate(int maxSize,
	int (*compare) (void* arg1, void* arg2)) {
	// Local Definitions
	HEAP* heap;
	
	// Statements
	heap = (HEAP*)malloc(sizeof(HEAP));
	if (!heap) {
		return NULL;
	}

	heap->size = 0; // missing in the book
	heap->last = -1;
	heap->compare = compare;

	// Force the heap size to be a power of 2 - 1
	// Allocating some extra space and probable performance increase
	heap->maxSize = (int)pow(2, ceil(log2(maxSize))) - 1;
	heap->heapAry = (void**)calloc(heap->maxSize, sizeof(void*));

	return heap;
}

/* heapInsert
  --------------
  Inserts data into heap.
  Pre. heap is a valid heap structure
 		last is pointer to index for last element
 		data is data to be inserted
  Post. data have been inserted into heap
  Return true if successful; false if array full
*/
bool heapInsert(HEAP* heap, void* dataPtr) {
	// Statements
	// if Heap is full
	if (heap->last == heap->maxSize - 1) {
		return false;
	}

	// insert and reheapUp
	++(heap->size); 
	++(heap->last); 
	heap->heapAry[heap->last] = dataPtr;

	_reheapUp(heap, heap->last);

	return true;
}

/* _reheapUp
  --------------
  Reestablishes the heap by moving data in child up to the correct
  location in the heap array.
  Pre.  heap is an invalid heap structure
 		childLoc is the index to the new data in the heap
  Post. the new data is inserted in the correct position of the heap
*/
void _reheapUp(HEAP* heap, int childLoc) {
	// Local Definitions
	int parent;
	void** heapAry;
	void* hold;

	// Statements
	// if not at root of heap -- index 0
	if (childLoc) {
		heapAry = heap->heapAry;
		parent = (childLoc - 1) / 2;
		// if child is greater than parent -- swap
		if (heap->compare(heapAry[childLoc], heapAry[parent]) > 0) {
			hold = heapAry[parent];
			heapAry[parent] = heapAry[childLoc];
			heapAry[childLoc] = hold;
			_reheapUp(heap, parent);
		}
	}

	return;
}

/* heapDelete
  --------------
  Deletes root of heap and passes data back to caller.
  Pre. heap is a valid heap structure
 		last is reference to last node in heap
       dataOutPtr is pointer to output area
  Post. root deleted and heap rebuild
        deleted data passed back to the user.
  Return true if deleted successfully, false if heap is empty
 */
bool heapDelete(HEAP* heap, void** dataOutPtr) {
	// Statements
	// if heap is empty
	if (heap->size == 0) {
		return false;
	}
	// delete the element and reheapDown
	*dataOutPtr = heap->heapAry[0];
	heap->heapAry[0] = heap->heapAry[heap->last];
	(heap->size)--;
	(heap->last)--;
	_reheapDown(heap, 0);
	
	return true;
}

/* _reheapDown
  --------------
  Reestablishes the heap by moving the data in the root down to its
  correct location in the heap.
  Pre. heap is an invalid heap structure
 	   root is the root of a heap or subheap
       last is the index to the last element in the heap
  Post. heap has been restored.
 */
void _reheapDown(HEAP* heap, int root) {
	// Local definitions
	void* hold;
	void* leftData;
	void* rightData;
	int largeLoc;
	int last;

	// Statements
	last = heap->last;
	// if root is not a leaf
	if ((root * 2 + 1) <= last) { // left subtree
		// there is at least one child
		leftData = heap->heapAry[root * 2 + 1];
		if ((root * 2 + 2) <= last) { // right subtree
			rightData = heap->heapAry[root * 2 + 2];
		}
		else {
			rightData = NULL;
		}

		// Determine which child is larger
		// if no right key or leftKey is greater
		if (!rightData || heap->compare(leftData, rightData) > 0) {
			largeLoc = root * 2 + 1;
		}
		else {
			largeLoc = root * 2 + 2;
		}

		// Test if root < largest subtree, swap, and reheapDown
		if (heap->compare(heap->heapAry[root], heap->heapAry[largeLoc]) < 0) {
			hold = heap->heapAry[root];
			heap->heapAry[root] = heap->heapAry[largeLoc];
			heap->heapAry[largeLoc] = hold;
			_reheapDown(heap, largeLoc);
		}
	}

	return;
}













































// Functions not developed in the book

/* heapCount
 -------------
 Returns number of elements in heap.
 Pre. valid heap
*/
int heapCount(HEAP* heap)
{
	return (heap->size);
}

/*	heapFull
 -------------
 Returns number of elements in heap.
 Pre. valid heap
*/
bool heapFull(HEAP* heap)
{
	//	Statements
	return (heap->size == heap->maxSize);
}	// heapFull

/*	heapEmpty
-------------
 Returns number of elements in heap.
 Pre. valid heap
*/
bool heapEmpty(HEAP* heap)
{
	return (heap->size == 0);
}

/*	heapDestroy
 -------------
 Destroys the heap.
 Pre. valid heap
 Post. heap destroyed
*/
void heapDestroy(HEAP* heap) {

	for (int i = 0; i < heap->size; i++) {
		free(heap->heapAry[i]);
	}
	free(heap->heapAry);
	free(heap);

	return;
}