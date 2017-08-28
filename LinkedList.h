#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	Node<T> * findNode(T newData, bool verbose);
	Node<T> * insertNode(T newData);
	Node<T> * removeNode(T newData, bool min);

private:
	Node<T> *head;
	Node<T> *tail;
};

template<typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	if (head != NULL) {
		Node<T> *current = head;
		while (current != tail) {
			Node<T> *tmp = current;
			current = current->getNext();
			delete[] tmp;
		}
	}
}

//Had quite a few issues with a count variable for the node. Might be a little messy

template<typename T>
Node<T> * LinkedList<T>::findNode(T newData, bool verbose) {
	//  Begin search at the start
	Node<T> *current = head;
	while (current != NULL) {
		T current_data = current->getData();
		//	If we find it, check whether or not to print message
		if (newData == current_data) {
			if (verbose) {
				cout << "found " << current_data << endl;
			}
			return current;
		}
		//	We haven't found it yet so try the next one
		current = current->getNext();
	}
	//	Print "not found" message if we need to
	if (verbose) {
		cout << newData  << " not found" << endl;
	}
	return NULL;
}

template<typename T>
Node<T> * LinkedList<T>::insertNode(T newData) {
	//	Check if  node is already in the list before we insert
	Node<T> *node = findNode(newData, false);

	if (node != NULL) {
		//	It's already in the list
		cout << "error: item already exists" << endl;
		//Attempt to avoid inputting into heap
		node->setCount(0);
	} else {
		// It's not in the list so we insert it by setting the next/prev pointers properly
		node = new Node<T>(newData);
		//	If LinkedList is empty: point next to the end
		if ((head == NULL) && (tail == NULL)) {
			head = node;
			node->setNext(tail);
			node->setPrev(NULL);
		}
		//  Otherwise: the current start is our new next
		else {
			node->setNext(head);
			node->setPrev(NULL);
			head->setPrev(node);
		}
		//    Point the Node to be at the start
		head = node;
		node->setCount(1);
	}
	return node;
}

template<typename T>
Node<T> * LinkedList<T>::removeNode(T newData, bool min) {
	//	Check if  node is already in the list before we insert
  Node<T> *node = findNode(newData, false);
  if (node != NULL) {
    //  Found element
    int count = node->getCount();
      // Delete node and Decrement count for later logic
      count--;
      node->setCount(count);
      
      /*** Rearrange pointers so node is removed from the list  ***/
      
      // Case 1: We are deleting the head
      if (node == head) {
	Node<T> *next_node = node->getNext();
	// Handle case where deletion makes list empty
	if (next_node != NULL) {
	  next_node->setPrev(NULL);
	  head = next_node;
	    } else {
	  // This deletion will casue list to be empty
	  head = NULL;
	  tail = NULL;
	}
      }
      // Case 2: We are deleting the tail
      else if (node->getNext() == NULL) {
	Node<T> *prev_node = node->getPrev();
	prev_node->setNext(NULL);
      }
      // Case 3: We are deleting some Node in the middle of the list
      else {
	Node<T> *prev_node = node->getPrev();
	Node<T> *next_node = node->getNext();
	prev_node->setNext(next_node);
	next_node->setPrev(prev_node);
      }
      if (min) {
	cout <<  node->getData() << endl;
      } else {
      }
  }
  else {
    cout << "error: item not present" << endl;
  }
  return node;
  
}
#endif
