#include <iostream>
#include <sstream>
#include <bitset>
#include "LinkedList.h"


int main()
{
	LinkedList<char> *list(new LinkedList<char>());

	list->push('c');
	list->push('b');
	list->push('d');
	std::cout << list;

	return 0;
}