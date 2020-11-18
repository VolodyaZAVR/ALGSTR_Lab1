#pragma once

class List
{
private:
	class Node
	{
		public:
			Node(int data, Node* next = nullptr)
			{
				this->data = data;
				this->next = next;
			};
			~Node() {};
			
			int data;
			Node* next;
	};
	Node* head;
	Node* tail;
	size_t _size;
	Node* get_head();
public:
	List();
	~List();

	void push_back(int); // добавление в конец списка
	void push_front(int); // добавление в начало списка
	void pop_back(); // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	void insert(int, size_t); // добавление элемента по индексу
	int at(size_t); // получение элемента по индексу
	void remove(size_t); // удаление элемента по индексу
	size_t get_size(); // получение размера списка
	void print_to_console(); // вывод элементов списка в консоль через разделитель
	void clear(); // удаление всех элементов списка
	void set(size_t, int); // замена элемента по индексу на передаваемый элемент
	bool isEmpty(); // проверка на пустоту списка
	bool contains(List); // проверка на содержание другого списка в списке
};
