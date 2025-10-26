#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int step = 1;
    
    cout << "Ищем " << target << " в массиве: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // Расчет позиции через интерполяцию
        int pos;
        if (arr[right] == arr[left]) {
            pos = left;
        } else {
            pos = left + (((double)(target - arr[left]) * (right - left)) / (arr[right] - arr[left]));
        }
        
        cout << "Шаг " << step << ": left=" << left << ", right=" << right;
        cout << ", pos=" << pos << " (элемент " << arr[pos] << ")" << endl;
        
        if (arr[pos] == target) {
            cout << "✓ Нашли на позиции " << pos << "!" << endl;
            return pos;
        } else if (arr[pos] < target) {
            cout << "  " << arr[pos] << " < " << target << " - ищем справа" << endl;
            left = pos + 1;
        } else {
            cout << "  " << arr[pos] << " > " << target << " - ищем слева" << endl;
            right = pos - 1;
        }
        
        step++;
    }
    
    cout << "✗ Элемент " << target << " не найден" << endl;
    return -1;
}

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 70;
    
    cout << "ИНТЕРПОЛИРУЮЩИЙ ПОИСК НА C++" << endl;
    cout << "============================" << endl;
    
    int result = interpolationSearch(numbers, target);
    
    return 0;
}