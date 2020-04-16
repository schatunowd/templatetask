#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Stack;
template<class T>
Stack<T> StackMerge(const Stack<T>& first, const Stack<T>& second);

template<class T>
class Stack
{
private:
	int size;
	T* array;
	int head;
	bool Empty()
	{
		if (head == size)
			return true;
		else
			return false;
	}
	bool Full()
	{
		if (head == 0)
			return true;
		else
			return false;
	}
public:
	Stack(int size)
	{
		this->size = size;
		this->array = new T[this->size];
		this->head = size;
	}
	Stack(const Stack& stack)
	{
		this->size = stack.size;
		this->array = new T[this->size];
		this->head = stack.head;
	}

	~Stack()
	{
		delete[] array;
	}

	void push(T element)
	{
		if (this->Full())
			throw std::out_of_range("Stack is full!");
		this->head = this->head - 1;
		this->array[this->head] = element;
	}

	T pop()
	{
		if (this->Empty())
			throw std::out_of_range("Stack is empty!");
		T element = this->array[this->head];
		this->head = this->head + 1;
		return element;
	}
	friend Stack StackMerge<T>(const Stack<T>& first, const Stack<T>& second);
};

template<class T>
Stack<T> StackMerge(const Stack<T>& first, const Stack<T>& second)
{
	int size = first.size + second.size;
	Stack<T> stack = Stack<T>(size);
	int index = first.size;
	while (index != first.head)
	{
		index = index - 1;
		stack.push(first.array[index]);
	}
	index = second.size;
	while (index != second.head)
	{
		index = index - 1;
		stack.push(second.array[index]);
	}
	return stack;
}
int main()
{
	Stack <int> stack1(5);
	Stack <int> stack2(5);
	stack1.push(10);
	stack1.push(2);
	stack1.push(4);
	stack1.push(1);
	stack1.push(15);
	stack2.push(32);
	stack2.push(11);
	stack2.push(12);
	stack2.push(14);
	stack2.push(17);
	stack1.pop();
	stack2.pop();
	StackMerge(stack1, stack2);
}
