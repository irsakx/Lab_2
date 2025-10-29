#include <iostream>
using namespace std;

int main() {
    int arr[100], n, leftStack[100], rightStack[100], sp = -1;
    int l, r, pivot, i, j, p, temp, k;

    cout << "Введите количество элементов: ";
    cin >> n;  // Ввод количества элементов массива

    cout << "Введите элементы массива: ";
    k = 0;
input_loop:
    if (k >= n) goto input_end;  // Если все элементы введены, переход к следующему этапу
    cin >> arr[k];  // Ввод элемента массива
    k++;
    goto input_loop;
input_end:

    sp++;
    leftStack[sp] = 0;  // Добавляем весь массив в стек (левая граница)
    rightStack[sp] = n - 1;  // Правая граница

sort_loop:
    if (sp < 0) goto print_array;  // Если стек пуст, сортировка завершена
    l = leftStack[sp];  // Извлекаем левую границу диапазона
    r = rightStack[sp];  // Извлекаем правую границу диапазона
    sp--;  // Убираем текущий диапазон из стека
    if (l >= r) goto sort_loop;  // Если один элемент или пустой диапазон, пропускаем

    pivot = arr[r];  // Опорный элемент (последний в диапазоне)
    i = l - 1;  // Индекс для разделения элементов
    j = l;  // Текущий индекс для прохода по массиву

partition_loop:
    if (j >= r) goto partition_end;  // Если дошли до конца, заканчиваем разделение
    if (arr[j] <= pivot) {  
        i++;  // Увеличиваем индекс меньших элементов
        temp = arr[i];  // Меняем местами arr[i] и arr[j]
        arr[i] = arr[j];
        arr[j] = temp;
    }
    j++;  
    goto partition_loop;

partition_end:
    p = i + 1;  // Определяем новую позицию опорного элемента
    temp = arr[p];  // Перемещаем опорный элемент на его место
    arr[p] = arr[r];
    arr[r] = temp;

    sp++;
    leftStack[sp] = l;  // Добавляем в стек левый подмассив
    rightStack[sp] = p - 1;

    sp++;
    leftStack[sp] = p + 1;  // Добавляем в стек правый подмассив
    rightStack[sp] = r;

    goto sort_loop;

print_array:
    k = 0;
print_loop:
    if (k >= n) goto end_print;  // Если все элементы выведены, завершаем
    cout << arr[k] << " ";  // Выводим элемент массива
    k++;
    goto print_loop;

end_print:
    cout << "\n";  // Завершаем программу
    return 0;
}
