#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
using namespace std;

template<typename T>
class HashTable {
public:
	HashTable(int table_size_in);
	~HashTable();

	int hash(T key);
	void lookup(T key);

	LinkedList<T> * get_bucket(T key);
	Node<T> * insert(T key);
	Node<T> * remove(T key, bool min);

private:
	LinkedList<T> *hash_table;
	int table_size;
};

template<typename T>
HashTable<T>::HashTable(int table_size_in) {
	table_size = table_size_in;
	hash_table = new LinkedList<T> [table_size];
}

template<typename T>
HashTable<T>::~HashTable() {
	delete[] hash_table;
}

template<typename T>
int HashTable<T>::hash(T key) {
	return (key % table_size);
}

template<typename T>
void HashTable<T>::lookup(T key) {
	LinkedList<T> *bucket = get_bucket(key);
	bucket->findNode(key, true);
}

template<typename T>
LinkedList<T> * HashTable<T>::get_bucket(T key) {
	int index;
	LinkedList<T> *bucket;
	index = hash(key);
	bucket = hash_table + index;
	return bucket;
}

template<typename T>
Node<T> * HashTable<T>::insert(T key) {
	LinkedList<T> *bucket = get_bucket(key);
	return bucket->insertNode(key);
}

template<typename T>
Node<T> * HashTable<T>::remove(T key, bool min) {
	LinkedList<T> *bucket = get_bucket(key);
	return bucket->removeNode(key, min);
}

#endif
