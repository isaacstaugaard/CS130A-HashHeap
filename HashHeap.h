#ifndef HASHHEAP_H
#define HASHHEAP_H

#include "HashTable.h"
#include "Heap.h"
using namespace std;

template<typename T>
class HashHeap {
public:
        //HashHeap Constructor
	HashHeap(int hashHeapSize);
	//Destructor
	~HashHeap();
	//Insert
	void insert(T element);
	//Remove
	void remove(T element);
	//RemoveMin
	void removeMin();
	//Lookup
	void lookup(T element);
	//Print
	void print();
private:
	//Instantiate 
	unsigned int HHSize;
	Heap<T> *heap;
	HashTable<T> *table;
};

//Construct the HashHeap. Also makes the Heap and HashTable
template<typename T>
HashHeap<T>::HashHeap(int hashHeapSize) {
	HHSize = hashHeapSize;
	heap = new Heap<T>(HHSize);
	table = new HashTable<T>(HHSize);
}

//Destructor
template<typename T>
HashHeap<T>::~HashHeap() {
	delete[] heap;
	delete[] table;
}

//Inserts into the hashtable and then tries to insert into the heap
//Make it so it checks before inserting into the hashtable too
template<typename T>
void HashHeap<T>::insert(T element) {
  Node<T> *node = table->insert(element);

  if (node!=NULL){
	if (node->getCount() == 1) {
		heap->insert(node);
	} else {
		// Don't insert duplicates into the heap
	}
  }
}

//Removes the element from the hashtable, then removes from the heap
template<typename T>
void HashHeap<T>::remove(T element) {
	Node<T> *node = table->remove(element, false);
	if (node != NULL) {
			heap->remove(node);
	}
}

//removes the min from the heap, then removes the value from the table
template<typename T>
void HashHeap<T>::removeMin() {
	Node<T> *node = heap->removeMin();
	if (node != NULL) {
		table->remove(node->getData(), true);
	} else {
		cout << "error: table is empty" << endl;
	}
}

//looksup the value in the hashtable
template<typename T>
void HashHeap<T>::lookup(T element) {
	table->lookup(element);
}

//prints the values
template<typename T>
void HashHeap<T>::print() {
	heap->print();
}

#endif
