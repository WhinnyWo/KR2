#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // Начинаем с большого промежутка, затем уменьшаем
    for (int gap = n/2; gap > 0; gap /= 2) {
        cout << "Промежуток: " << gap << endl;
        cout << "Текущий массив: ";
        for (int num : arr) cout << num << " ";
        cout << endl;
        
        // Выполняем сортировку вставками для этого промежутка
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            // Сдвигаем элементы, пока не найдем правильную позицию
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
            
            cout << "  Вставили " << temp << ": ";
            for (int num : arr) cout << num << " ";
            cout << endl;
        }
    }
}