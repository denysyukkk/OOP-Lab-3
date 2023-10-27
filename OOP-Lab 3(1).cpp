// OOP-Lab 3(1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
 
using System;

class Program
{
    static void Main()
    {
        double[] numbers = { -28.35, 12.91 };
        int k = 2; // Кількість перших елементів для впорядкування

        // 1. Знайдення добутку індексів від'ємних елементів
        double productOfNegativeIndices = 1;
        for (int i = 0; i < numbers.Length; i++)
        {
            if (numbers[i] < 0)
            {
                productOfNegativeIndices *= i;
            }
        }

        Console.WriteLine("Добуток індексів від'ємних елементів: " + productOfNegativeIndices);

        // 2. Впорядкування перших k елементів за спаданням їх значень
        Array.Sort(numbers, 0, k, Comparer<double>.Create((a, b) = > b.CompareTo(a)));

        Console.WriteLine("Перші " + k + " елементи, впорядковані за спаданням:");
        foreach(var number in numbers)
        {
            Console.WriteLine(number);
        }
    }
}
