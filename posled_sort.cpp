#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    cout << "Ищем элемент " << target << " в массиве: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    for (int i = 0; i < arr.size(); i++) {
        cout << "  Проверяем элемент [" << i << "] = " << arr[i] << endl;
        
        if (arr[i] == target) {
            cout << "  ✓ Нашли на позиции " << i << "!" << endl;
            return i;
        }
    }
    
    cout << "  ✗ Элемент " << target << " не найден" << endl;
    return -1;
}

int main() {
    vector<int> numbers = {4, 2, 8, 1, 9, 3, 7};
    int target = 9;
    
    cout << "ПОСЛЕДОВАТЕЛЬНЫЙ ПОИСК НА C++" << endl;
    cout << "=============================" << endl;
    
    int result = linearSearch(numbers, target);
    
    if (result != -1) {
        cout << "Результат: элемент найден на позиции " << result << endl;
    } else {
        cout << "Результат: элемент не найден" << endl;
    }
    
    return 0;
}