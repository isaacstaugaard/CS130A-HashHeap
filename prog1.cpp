#include <iostream>
#include <string>
#include "HashHeap.h"
using namespace std;

int main() {
	HashHeap<int> *h = new HashHeap<int>(101);
	string dummyLine;
	//Scan over the first two lines, not doing extracredit
	getline(cin, dummyLine);
	getline(cin,dummyLine);

	while (!cin.eof()) {
		string command;
		cin >> command;

		if (command.compare("insert") == 0) {
			int iValue;
			cin >> iValue;
			h->insert(iValue);
		} else if (command.compare("lookup") == 0) {
			int iValue;
			cin >> iValue;
			h->lookup(iValue);
		} else if (command.compare("delete") == 0) {
			int iValue;
			cin >> iValue;
			h->remove(iValue);
		} else if (command.compare("deleteMin") == 0) {
			h->removeMin();
		} else if (command.compare("print") == 0) {
		       h->print();
		} else if (cin.eof()) {
			break;
		} else {
			cout << "Invalid input." << endl;
		}
	}

	return 0;
}
