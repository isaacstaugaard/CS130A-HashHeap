#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	Node(T newData);
	~Node();

	Node<T> * getNext();
	void setNext(Node<T> *newNext);

	Node<T> * getPrev();
	void setPrev(Node<T> *newPrev);

	T getData();
	void setData(T newData);

	int getCount();
	void setCount(int newCount);

	int getIndex();
	void setIndex(int newIndex);

	Node<T> *next;
	Node<T> *prev;

private:
	T data;
	int count;
	int index;
};

template<typename T>
Node<T>::Node(T newData) {
	data = newData;
	count = 0;
	index = -1;
	next = NULL;
	prev = NULL;
}

template<typename T>
Node<T>::~Node() {
	delete[] next;
	delete[] prev;
}

template<typename T>
Node<T> * Node<T>::getNext() {
	return next;
}

template<typename T>
void Node<T>::setNext(Node<T> *newNext) {
	next = newNext;
}

template<typename T>
Node<T> * Node<T>::getPrev() {
	return prev;
}

template<typename T>
void Node<T>::setPrev(Node<T> *newPrev) {
	prev = newPrev;
}

template<typename T>
T Node<T>::getData() {
	return data;
}

template<typename T>
void Node<T>::setData(T newData) {
	data = newData;
}

template<typename T>
int Node<T>::getCount() {
	return count;
}

template<typename T>
void Node<T>::setCount(int newCount) {
	count = newCount;
}

template<typename T>
int Node<T>::getIndex() {
	return index;
}

template<typename T>
void Node<T>::setIndex(int newIndex) {
	index = newIndex;
}

#endif
