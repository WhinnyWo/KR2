#include <iostream>
#include <vector>

using namespace std;

// Базовая версия
void bubbleSortBasic(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем элементы местами
                swap(arr[j], arr[j + 1]);
            }
        }
        
        cout << "Проход " << i + 1 << ": ";
        for (int num : arr) cout << num << " ";
        cout << endl;
    }
}
