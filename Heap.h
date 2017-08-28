#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "Node.h"
using namespace std;

template<typename T>
class Heap {
public:
	Heap(int heap_size_in);
	~Heap();

	void print();
	Node<T> * insert(Node<T> *node);
	Node<T> * remove(Node<T> *node);
	Node<T> * removeMin();

private:
	vector<Node<T> *> *heap;
	unsigned int heap_count;
	void percolate_up(Node<T> *node);
	void percolate_down(unsigned int hole);
};

template<typename T>
Heap<T>::Heap(int heap_size_in) {
	heap_count = 0;
	heap = new vector<Node<T> *>(heap_size_in);
}

template<typename T>
Heap<T>::~Heap() {
	delete[] heap;
}

template<typename T>
void Heap<T>::print() {
  for (unsigned int k = 1; k <= heap_count; k++) {
    cout << heap->at(k)->getData() << " ";
  }
  cout << endl;
}



template<typename T>
Node<T> * Heap<T>::insert(Node<T> *node) {
	//	Resize if the heap gets too full
	if (heap_count == (heap->size() - 1)) {
		heap->resize(heap->size() * 2);
	}
	percolate_up(node);
	return node;
}

template<typename T>
Node<T> * Heap<T>::remove(Node<T> *node) {
	int index = node->getIndex();

	if (node != NULL) {
		heap->at(index) = NULL;
		heap->at(index) = heap->at(heap_count);
		heap_count--;
		if (heap->at(index) != NULL) {
			heap->at(index)->setIndex(index);
		} else {
			return node;
		}
		percolate_down(index);
	}
	return node;
}

template<typename T>
Node<T> * Heap<T>::removeMin() {
	Node<T> *min = heap->at(1);

	if (min != NULL) {
			heap->at(1) = NULL;
			heap->at(1) = heap->at(heap_count);
			heap_count--;
			if (heap->at(1) != NULL) {
				heap->at(1)->setIndex(1);
			} else {
				return min;
			}
			percolate_down(1);
	}
	return min;
}

//Place the node into index 0 and then compare with the root. Make necessary changes and then clear index 0
template<typename T>
void Heap<T>::percolate_up(Node<T> *node) {
	heap_count++;
	int hole = heap_count;

	heap->at(0) = node;
	for (; node->getData() < heap->at(hole / 2)->getData(); hole /= 2) {
		Node<T> *tmp = heap->at(hole / 2);
		heap->at(hole) = tmp;
		heap->at(hole)->setIndex(hole);
		tmp = NULL;
	}
	heap->at(hole) = heap->at(0);
	heap->at(hole)->setIndex(hole);
	heap->at(0) = NULL;
}

template<typename T>
void Heap<T>::percolate_down(unsigned int hole) {
	unsigned int child;
	Node<T> *tmp = heap->at(hole);
	heap->at(hole) = NULL;

	for (; hole * 2 <= heap_count; hole = child) {
		child = hole * 2;
		if ((child != heap_count)
				&& (heap->at(child + 1)->getData()
						< heap->at(child)->getData())) {
			child++;
		}
		if (heap->at(child)->getData() < tmp->getData()) {
			heap->at(hole) = heap->at(child);
			heap->at(hole)->setIndex(hole);
			heap->at(child) = NULL;
		} else {
			break;
		}
	}
	heap->at(hole) = tmp;
	heap->at(hole)->setIndex(hole);
}

#endif
