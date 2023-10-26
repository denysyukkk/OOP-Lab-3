﻿// OOP-Lab 3(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cout << "Введіть кількість рядків масиву: ";
    std::cin >> n;
    std::cout << "Введіть кількість стовпців масиву: ";
    std::cin >> m;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));

    // Заповнення масиву псевдовипадковими числами в діапазоні [-24.9, 60.3]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = -24.9 + static_cast<double>(rand()) / RAND_MAX * (60.3 - (-24.9));
        }
    }

    std::cout << "Початкова матриця:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::fixed << std::setprecision(1) << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Знайдемо кількість рядків, які не містять жодного від'ємного елемента
    int rowsWithoutNegatives = 0;
    for (int i = 0; i < n; ++i) {
        bool hasNegative = false;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative) {
            ++rowsWithoutNegatives;
        }
    }
    std::cout << "Кількість рядків без від'ємних елементів: " << rowsWithoutNegatives << std::endl;

    // Сортування рядків за спаданням сум елементів у рядках
    std::sort(matrix.begin(), matrix.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
        double sumA = std::accumulate(a.begin(), a.end(), 0.0);
    double sumB = std::accumulate(b.begin(), b.end(), 0.0);
    return sumA > sumB;
        });

    std::cout << "Матриця після сортування за сумою елементів у рядках:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::fixed << std::setprecision(1) << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}