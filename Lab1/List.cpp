#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

List::~List()
{
	clear();
}

List::Node* List::get_head()
{
	return head;
}
void List::push_back(int data)
{
	if (!_size)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		tail->next = new Node(data);
		tail = tail->next;
	}
	_size++;
}

void List::push_front(int data)
{
	Node* temp_node;
	if (!_size)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		temp_node = new Node(data, head);
		head = temp_node;
	}
	_size++;
}

void List::pop_back()
{
	Node* temp_node = head;
	if (!_size)
		return;
	else
	{
		if (_size == 1)
		{
			temp_node->~Node();
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			while (temp_node->next != tail)
				temp_node = temp_node->next;
			tail = temp_node;
			temp_node->next->~Node();
			tail->next = nullptr;
		}
		_size--;
	}
}

void List::pop_front()
{
	Node* temp_node = head;
	if (!_size)
		return;
	else
	{
		if (_size == 1)
		{
			temp_node->~Node();
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->next;
			temp_node->~Node();
		}
		_size--;
	}
}

void List::insert(int data, size_t index)
{
	size_t cnt = 1;
	Node* temp_node = head;
	Node* new_node = nullptr;
	if (index == 0)
		push_front(data);
	else if (index >= _size)
		throw out_of_range("Index out of range!");
	else
	{
		while (cnt != index) 
		{
			temp_node = temp_node->next;
			cnt++;
		}
		new_node = new Node(data, temp_node->next);
		temp_node->next = new_node;
		_size++;
	}
}

int List::at(size_t index)
{
	size_t cnt = 0;
	Node* temp_node = head;
	if (index >= _size)
		throw out_of_range("Index out of range!");
	else
	{
		while (cnt != index)
		{
			temp_node = temp_node->next;
			cnt++;
		}
		return temp_node->data;
	}
}

void List::remove(size_t index)
{
	size_t cnt = 0;
	Node* temp_node1 = head;
	Node* temp_node2 = nullptr;
	if (index >= _size)
		throw out_of_range("Index out of range!");
	else
	{
		if (!_size)
			return;
		else
		{
			if (index == 0)
				pop_front();
			else if (index == _size - 1)
				pop_back();
			else
			{
				while (cnt != index - 1)
				{
					temp_node1 = temp_node1->next;
					cnt++;
				}
				temp_node2 = temp_node1->next->next;
				temp_node1->next->~Node();
				temp_node1->next = temp_node2;
				_size--;
				if (_size == 0)
				{
					head = nullptr;
					tail = nullptr;
				}
			}
		}
	}
}

size_t List::get_size()
{
	return _size;
}

void List::print_to_console()
{
	Node* temp_node = head;
	while (temp_node)
	{
		cout << temp_node->data << ' ';
		temp_node = temp_node->next;
	}
	cout << endl;
}

void List::clear()
{
	Node* temp_node1 = head;
	Node* temp_node2 = nullptr;
	if (!_size)
		return;
	else
	{
		if (_size == 1)
		{
			temp_node1->~Node();
		}
		else
		{
			temp_node2 = head->next;
			while (temp_node2)
			{
				temp_node1 ->~Node();
				temp_node1 = temp_node2;
				temp_node2 = temp_node2->next;
			}
			temp_node1->~Node();
		}
		head = nullptr;
		tail = nullptr;
		_size = 0;
	}
}

void List::set(size_t index, int data)
{
	Node* temp_node = head;
	Node* new_node = nullptr;
	if (index >= _size)
		throw out_of_range("Index out of range!");
	else if (!_size)
		return;
	else
	{
		if (index == 0)
		{
			new_node = new Node(data, head->next);
			temp_node->~Node();
			head = new_node;
		}
		else
		{
			for (size_t i = 0; i < index - 1; i++)
				temp_node = temp_node->next;
			if (temp_node->next->next)
				new_node = new Node(data, temp_node->next->next);
			else
			{
				new_node = new Node(data);
				tail = new_node;
			}
			temp_node->next->~Node();
			temp_node->next = new_node;
		}
	}
}

bool List::isEmpty()
{
	return(!_size);
}

bool List::contains(List list)
{
	bool flag;
	Node* temp_node1 = head;
	Node* temp_node2 = nullptr, *list2_node = nullptr;
	while (temp_node1 != nullptr)
	{
		flag = false;
		temp_node2 = temp_node1;
		list2_node = list.get_head();
		while (list2_node != nullptr)
		{
			if (temp_node2->data != list2_node->data)
			{
				flag = true;
				break;
			}
			temp_node2 = temp_node2->next;
			list2_node = list2_node->next;
		}
		if (!flag)
			return true;
		temp_node1 = temp_node1->next;
	}
	return false;
}