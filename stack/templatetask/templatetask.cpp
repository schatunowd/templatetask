#include <iostream>
#include <stack>
#include <clocale>
using namespace std;

template <class T>
class Stack;

template<class T>
class Stack
{
private:
    T* array;
    int size;
    int head;
public:
    Stack(int Full) 
    {
        this->size = Full;
        this->array = new T[size];
        this->head = 0;
    }
    Stack(const Stack<T>& stack) 
    {
        this->head = stack.head;
        this->array = new T[Stack.size];
        this->array = stack.array;
    }
    void push(T elem)
    {
        if (this->head >= this->size)
            throw out_of_range("Stack is full");
        array[this->head++] = elem;
    }
    void pop()
    {
        if (this->head <= 0)
            throw out_of_range("Stack is empty");
        this->head--;
    }
    void out()
    {
        for (int i = 0; i < head; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    ~Stack()
    {
        delete[] array;
    }
    void StackMerge(const Stack<T>& second);
};
template<typename T>
void Stack<T>::StackMerge(const Stack<T>& second)
{
    T* merge = new T[size + second.size];
    head = 0;
    while (head < size) {
        merge[head] = array[head];
        head++;
    }
    while (head < size + second.size) {
        merge[head] = second.array[head - size];
        head++;
    }
    array = merge;
}
int main()
{
    setlocale(0, "");
    Stack <int> stack1(5);
    Stack <int> stack2(5);
    cout << "Стэк 1: ";
    stack1.push(10);
    stack1.push(2);
    stack1.push(4);
    stack1.push(1);
    stack1.push(15);
    stack1.out();
    cout << "Стэк 2: ";
    stack2.push(32);
    stack2.push(11);
    stack2.push(12);
    stack2.push(14);
    stack2.push(17);
    stack2.out();
    cout << "Стэк 1 после удаления нового элемента: ";
    stack1.pop();
    stack1.out();
    cout << "Стэк 2 после удаления нового элемента: ";
    stack2.pop();
    stack2.out();
    Stack <int> stack3(10);
    stack1.StackMerge(stack2);
    cout << "Новый стэк после слияния: ";
    stack1.out();
}