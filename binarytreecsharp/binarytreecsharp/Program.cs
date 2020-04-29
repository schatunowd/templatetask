using System;

namespace binarytreecsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTreeClass<int> binarytree = new BinaryTreeClass<int>(60, null);
            binarytree.Add(10);
            binarytree.Add(20);
            binarytree.Add(30);
            binarytree.Add(40);
            binarytree.Add(50);
            Console.Write("Бинарное дерево: ");
            binarytree.print();
            binarytree.remove(20);
            Console.Write("Удаляем узел 20: ");
            binarytree.print();
            Console.Write("Поиск узла: ");
            binarytree.search(30).print();
        }
    }
}
