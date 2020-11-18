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

	void push_back(int); // ���������� � ����� ������
	void push_front(int); // ���������� � ������ ������
	void pop_back(); // �������� ���������� ��������
	void pop_front(); // �������� ������� ��������
	void insert(int, size_t); // ���������� �������� �� �������
	int at(size_t); // ��������� �������� �� �������
	void remove(size_t); // �������� �������� �� �������
	size_t get_size(); // ��������� ������� ������
	void print_to_console(); // ����� ��������� ������ � ������� ����� �����������
	void clear(); // �������� ���� ��������� ������
	void set(size_t, int); // ������ �������� �� ������� �� ������������ �������
	bool isEmpty(); // �������� �� ������� ������
	bool contains(List); // �������� �� ���������� ������� ������ � ������
};
