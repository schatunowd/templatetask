using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Stack_Csharp_
{
    class StackClass<T>
    {
        public Stack<T> stack;
        int l;
        public StackClass(int length)
        {
            if (length > 0)
            {
                this.l = length;
                stack = new Stack<T>();
            }
            else
                throw new ArgumentException();
        }
        public StackClass(StackClass<T> s1, StackClass<T> s2)
        {
            this.l = s1.stack.Count() + s2.stack.Count();
            stack = new Stack<T>();
            Stack<T> st1 = s1.stack;
            Stack<T> st2 = s2.stack;
            while (st1.Count() != 0)
            {
                Push(st1.First());
                st1.Pop();
            }
            while (st2.Count() != 0)
            {
                Push(st2.First());
                st2.Pop();
            }
        }
        public void Pop()
        {
            if (stack.Count > 0)
                stack.Pop();

        }

        public void print(int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.Write(stack.ElementAt(i));
                Console.Write(" ");
            }
            Console.WriteLine();
        }

        public void Push(T element)
        {
            stack.Push(element);
            if (stack.Count() > this.l)
            {
                Pop();
                throw new IndexOutOfRangeException("Переполнение стека");
            }
        }
        ~StackClass() 
        { 
        }
    }
}
