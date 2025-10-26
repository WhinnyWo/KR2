#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Элемент для вставки
        int j = i - 1;
        
        // Сдвигаем элементы, большие чем key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Вставляем key в правильную позицию
        arr[j + 1] = key;
        
        // Вывод промежуточного состояния
        cout << "Шаг " << i << ": ";
        for (int num : arr) cout << num << " ";
        cout << "(вставлен " << key << ")" << endl;
    }
}