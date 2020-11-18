#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List* list = new List();
	List* list2 = new List();
	list->push_back(3);
	list->push_back(4);
	list->push_back(5);
	list->push_back(5);
	list->push_back(6);
	list->push_back(7);
	list->push_back(8);

	list2->push_back(6);
	list2->push_back(7);
	list2->push_back(8);
	if (list->contains(*list2))
		cout << 1;
	else
		cout << 0;
	delete list2;
	delete list;
	return 0;
}