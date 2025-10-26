#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Проходим по всем элементам массива
    for (int i = 0; i < n - 1; i++) {
        // Находим индекс минимального элемента в неотсортированной части
        int minIndex = i;
        
        // Ищем минимальный элемент среди оставшихся
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Меняем местами найденный минимальный элемент 
        // с первым неотсортированным
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        
        // Выводим промежуточное состояние (для наглядности)
        cout << "Шаг " << i + 1 << ": ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}