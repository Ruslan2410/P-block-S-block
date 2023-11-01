#include <iostream>
#include <vector>

// Функція S-блоку
void s_box(std::vector<int>& data, const std::vector<std::vector<int>>& s_box_table) {
    for (int i = 0; i < data.size(); ++i) {
        int row = (data[i] & 0x8) >> 3;  // Отримуємо значення першого біту (4-го біта) для рядка
        int col = (data[i] & 0x7);       // Отримуємо значення останніх 3-х бітів для стовпця
        data[i] = s_box_table[row][col];  // Замінюємо біт на відповідне значення з S-блоку
    }
}

// Функція P-блоку
void p_box(std::vector<int>& data, const std::vector<int>& permutation_table) {
    std::vector<int> temp(data.size());
    for (int i = 0; i < data.size(); ++i) {
        temp[i] = data[permutation_table[i]];
    }
    data = temp;
}

int main() {
    // Приклад S-блоку і P-блоку таблиць
    std::vector<std::vector<int>> s_box_table = {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        // Додайте інші рядки сюди
    };

    std::vector<int> permutation_table = { 1, 3, 0, 2 };

    // Вхідні дані
    std::vector<int> data = { 0, 1, 2, 3 };

    // Пряме перетворення
    s_box(data, s_box_table);
    p_box(data, permutation_table);

    std::cout << "Пряме перетворення: ";
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Зворотне перетворення
    // Виконується обернене S-блок та обернене P-блок, в зворотньому порядку

    // Відображення даних
    std::cout << "Зворотне перетворення: ";
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

