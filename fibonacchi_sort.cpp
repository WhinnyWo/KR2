#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibonacciSearch(vector<int>& arr, int target) {
    int n = arr.size();
    
    // Генерация чисел Фибоначчи
    int fibM2 = 0; // F(m-2)
    int fibM1 = 1; // F(m-1)
    int fibM = fibM2 + fibM1; // F(m)
    
    cout << "Генерация чисел Фибоначчи:" << endl;
    
    // Находим наименьшее число Фибоначчи >= n
    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
        cout << "F(m-2)=" << fibM2 << ", F(m-1)=" << fibM1 << ", F(m)=" << fibM << endl;
    }
    
    int offset = -1;
    int step = 1;
    
    cout << "\nНачало поиска:" << endl;
    
    while (fibM > 1) {
        cout << "\nШаг " << step << ":" << endl;
        cout << "F(m)=" << fibM << ", F(m-1)=" << fibM1 << ", F(m-2)=" << fibM2 << endl;
        
        // Проверяем элемент в позиции offset + fibM2
        int i = min(offset + fibM2, n - 1);
        
        cout << "Проверяем позицию " << i << ": " << arr[i] << endl;
        
        if (arr[i] < target) {
            cout << arr[i] << " < " << target << " - двигаемся вправо" << endl;
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i] > target) {
            cout << arr[i] << " > " << target << " - двигаемся влево" << endl;
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            cout << "Найдено на позиции " << i << "!" << endl;
            return i;
        }
        
        step++;
    }
    
    // Проверка последнего элемента
    if (fibM1 && offset + 1 < n && arr[offset + 1] == target) {
        cout << "Найдено на позиции " << offset + 1 << "!" << endl;
        return offset + 1;
    }
    
    cout << "Элемент не найден" << endl;
    return -1;
}

int main() {
    vector<int> numbers = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int target = 85;
    
    cout << "ПОИСК ФИБОНАЧЧИ НА C++" << endl;
    cout << "======================" << endl;
    
    int result = fibonacciSearch(numbers, target);
    
    return 0;
}