#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Ввод данных
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int arr[n];  // Объявление массива (VLA, работает в некоторых компиляторах)
    cout << "Enter " << n << " numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Инициализация стека для хранения границ сортировки
    stack<pair<int, int>> st;
    st.push(make_pair(0, n-1));  // Начинаем с сортировки всего массива

    // Основной цикл обработки подмассивов
    while(!st.empty()) {
        // Извлекаем текущие границы
        int low = st.top().first;
        int high = st.top().second;
        st.pop();
        
        // Пропускаем невалидные/пустые подмассивы
        if(low >= high) continue;
        
        // Партицирование (разделение элементов относительно опорного)
        int pivot = arr[high];  // Опорный элемент - последний в подмассиве
        int i = low;            // Индекс для вставки меньших элементов
        
        // Проход по текущему подмассиву
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                swap(arr[i], arr[j]);  // Переносим меньшие элементы влево
                i++;
            }
        }
        swap(arr[i], arr[high]);  // Ставим опорный элемент на правильную позицию
        
        // Добавляем левую и правую части для дальнейшей сортировки
        st.push(make_pair(low, i-1));   // Левая часть (меньшие элементы)
        st.push(make_pair(i+1, high));  // Правая часть (большие элементы)
    }

    // Вывод отсортированного массива
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}