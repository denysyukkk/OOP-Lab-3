// OOP-Lab 3.(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

double[, ] matrix = { { -24.9, 60.3 }, { 10.2, 15.7 }, { 5.5, 8.9 } }; // Приклад матриці з двома рядками та двома стовпцями
int rowsWithoutNegativeElement = 0;

for (int i = 0; i < matrix.GetLength(0); i++)
{
    bool hasNegativeElement = false;
    for (int j = 0; j < matrix.GetLength(1); j++)
    {
        if (matrix[i, j] < 0)
        {
            hasNegativeElement = true;
            break;
        }
    }
    if (!hasNegativeElement)
    {
        rowsWithoutNegativeElement++;
    }
}

Console.WriteLine("Кількість рядків без від'ємних елементів: " + rowsWithoutNegativeElement);

double[, ] matrix = { { -24.9, 60.3 }, { 10.2, 15.7 }, { 5.5, 8.9 } }; // Приклад матриці з двома рядками та двома стовпцями

// Обчислюємо суми елементів у кожному рядку
double[] rowSums = new double[matrix.GetLength(0)];
for (int i = 0; i < matrix.GetLength(0); i++)
{
    double sum = 0;
    for (int j = 0; j < matrix.GetLength(1); j++)
    {
        sum += matrix[i, j];
    }
    rowSums[i] = sum;
}

// Сортуємо рядки за спаданням їх сум
Array.Sort(rowSums, matrix);

Console.WriteLine("Матриця після перестановки за спаданням сум елементів у рядках:");
for (int i = 0; i < matrix.GetLength(0); i++)
{
    for (int j = 0; j < matrix.GetLength(1); j++)
    {
        Console.Write(matrix[i, j] + " ");
    }
    Console.WriteLine();
}
