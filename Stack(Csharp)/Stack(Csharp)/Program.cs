using System;
using System.Linq;

namespace Stack_Csharp_
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 5, n2 = 4;
            StackClass<int> stack1 = new StackClass<int>(n);
            StackClass<int> stack2 = new StackClass<int>(n);
            stack1.Push(2);
            stack1.Push(4);
            stack1.Push(6);
            stack1.Push(8);
            stack1.Push(10);
            Console.Write("Первый стэк: ");
            stack1.print(n);
            stack2.Push(1);
            stack2.Push(3);
            stack2.Push(5);
            stack2.Push(7);
            stack2.Push(9);
            Console.Write("Второй стэк: ");
            stack2.print(n);
            stack1.Pop();
            Console.Write("Первый стэк после удаления первого элемента: ");
            stack1.print(n2);
            stack2.Pop();
            Console.Write("Второй стэк после удаления первого элемента: ");
            stack2.print(n2);
            Console.Write("Объединение двух стэков: ");
            StackClass<int> stack3 = new StackClass<int>(stack1, stack2);
            stack3.print(8);
        }
    }
}