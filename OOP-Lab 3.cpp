// OOP-Lab 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;

    std::vector<double> numbers(n);

    // Заповнення масиву псевдовипадковими числами в діапазоні [-28.35, 12.91]
    for (int i = 0; i < n; ++i) {
        numbers[i] = -28.35 + static_cast<double>(rand()) / RAND_MAX * (12.91 - (-28.35));
    }

    std::cout << "Початковий масив: ";
    for (const auto& num : numbers) {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
    std::cout << std::endl;

    // Знайдемо добуток індексів від'ємних елементів
    int negativeProduct = 1;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] < 0) {
            negativeProduct *= i;
        }
    }
    std::cout << "Добуток індексів від'ємних елементів: " << negativeProduct << std::endl;

    // Введення значення k та впорядкування перших k елементів за спаданням
    std::cout << "Введіть кількість перших елементів для сортування: ";
    std::cin >> k;

    std::partial_sort(numbers.begin(), numbers.begin() + k, numbers.end(), std::greater<double>());

    std::cout << "Відсортовані перші " << k << " елементів за спаданням: ";
    for (int i = 0; i < k; ++i) {
        std::cout << std::fixed << std::setprecision(2) << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
