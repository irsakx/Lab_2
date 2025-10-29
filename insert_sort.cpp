#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 1, 4, 2};  // Исходный массив
    int n = sizeof(arr) / sizeof(arr[0]);  // Размер массива

    // Алгоритм сортировки вставками
    for (int i = 1; i < n; i++) {         // Начинаем со второго элемента
        int key = arr[i];                 // Текущий элемент для вставки
        int j = i - 1;                    // Индекс предыдущего элемента

        // Сдвигаем элементы больше key вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Вставляем key в правильную позицию
    }

    // Вывод отсортированного массива
    cout << "После сортировки: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}