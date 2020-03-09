#include <iostream>
using namespace std;

template<class T>
class Stack
{
private:
	int size;
	T* arr;
	int head;
	bool empty()
	{
		if (head == size)
			return true;
		else
			return false;
	}
	bool overflow()
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
		this->arr = new T[this->size];
		this->head = size;
	}
	Stack(const Stack& stack)
	{
		this->size = stack.size;
		this->arr = new T[this->size];
		this->head = stack.head;
	}

	~Stack()
	{
		delete[] arr;
	}

	void push(T element)
	{
		if (this->overflow())
			cout << "Stack is overflowed";
		this->head = this->head - 1;
		this->arr[this->head] = element;
	}

	int pop(T elememt)
	{
		if (this->empty())
			cout << "Stack is empty";
		T element = this->arr[this->head];
		this->head = this->head + 1;
		return element;
	}
};

template<class T>
Stack<T> stackunion(const Stack<T>& stack1, const Stack<T>& stack2)
{
	int size = stack1.size + stack2.size;
	Stack<T> stack3 = Stack<T>(size);
	int i = stack1.size;
	while (i != stack1.head)
	{
		i--;
		stack.push(stack1.array[i]);
	}
	i = stack2.size;
	while (i != stack2.head)
	{
		i--;
		stack.push(stack2.array[i]);
	}
	return stack;
}

int main()
{
	int s = 10;
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
	stack1.pop(10);
	stack2.pop(14);
	stackunion(stack1, stack2);
}
